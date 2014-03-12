#!/usr/bin/perl -w
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#
# This Source Code Form is "Incompatible With Secondary Licenses", as
# defined by the Mozilla Public License, v. 2.0.

###############################################################################
# Script Initialization
###############################################################################

# Make it harder for us to do dangerous things in Perl.
use strict;

# Include the Bugzilla CGI and general utility library.
use lib qw(. lib maestrano/lib/perl-libs/lib/perl5);

use Bugzilla;
use Bugzilla::Constants;
use Bugzilla::Error;
use Bugzilla::Update;

# Hook:Maestrano
# Load Maestrano
require "./maestrano/app/init/base.pm";
my $maestrano = MaestranoService->instance();

# Check whether or not the user is logged in
my $user = Bugzilla->login(LOGIN_OPTIONAL);
my $cgi = Bugzilla->cgi;
my $template = Bugzilla->template;
my $vars = {};

# And log out the user if requested. We do this first so that nothing
# else accidentally relies on the current login.
if ($cgi->param('logout')) {
    Bugzilla->logout();
    $user = Bugzilla->user;
    $vars->{'message'} = "logged_out";
    # Make sure that templates or other code doesn't get confused about this.
    $cgi->delete('logout');
}

# Hook:Maestrano
# Require authentication straight away if intranet
# mode enabled
if ($maestrano->is_sso_intranet_enabled()) {
  if (!$maestrano->get_sso_session()->is_valid()) {
    print $cgi->redirect($maestrano->get_sso_init_url());
  }
}

# Check Maestrano Session is still valid if user is
# logged in
if ($user->id && $maestrano->is_sso_enabled()) {
  if (!$maestrano->get_sso_session()->is_valid()) {
    Bugzilla->logout();
  }
}

###############################################################################
# Main Body Execution
###############################################################################

# Return the appropriate HTTP response headers.
print $cgi->header();

if ($user->in_group('admin')) {
    # If 'urlbase' is not set, display the Welcome page.
    unless (Bugzilla->params->{'urlbase'}) {
        $template->process('welcome-admin.html.tmpl')
          || ThrowTemplateError($template->error());
        exit;
    }
    # Inform the administrator about new releases, if any.
    $vars->{'release'} = Bugzilla::Update::get_notifications();
}

# Generate and return the UI (HTML page) from the appropriate template.
$template->process("index.html.tmpl", $vars)
  || ThrowTemplateError($template->error());
