#-----------------------------------------------
# Require Library folder
#-----------------------------------------------
use Cwd 'abs_path';

my $lib_path;
my $app_path;
my $perl_libs_path;
BEGIN {
  $app_path = abs_path(__FILE__ . '/../../../app');
  $lib_path = abs_path(__FILE__ . '/../../../lib');
  $perl_libs_path = abs_path(__FILE__ . '/../../../lib/perl-libs/lib/perl5');
}

#-----------------------------------------------
# Require perl-libs
#-----------------------------------------------
use lib $perl_libs_path;

#-----------------------------------------------
# Require JSON
#-----------------------------------------------
use lib $lib_path . '/json/lib';
use lib $lib_path . '/json/lib/JSON';

#-----------------------------------------------
# Require Net::SAML2 dependencies
#-----------------------------------------------
use lib $lib_path . '/uri-fromhash/lib';
use lib $lib_path . '/moosex-types-uri/lib';
use lib $lib_path . '/net-saml/lib/';

use Net::SAML2::IdP;
use Net::SAML2::Binding::Redirect;
use Net::SAML2::Protocol::AuthnRequest;
use Net::SAML2::Binding::POST;
use Net::SAML2::Protocol::Assertion;

#-----------------------------------------------
# Require Maestrano Libraries
#-----------------------------------------------
# Require Maestrano 
use lib $lib_path . '/mno-perl/src';
use lib $lib_path . '/mno-perl/src/sso';

use MnoSettings;
use MnoSsoBaseUser;
use MnoSsoSession;
use MaestranoService;


#-----------------------------------------------
# Require Maestrano app files
#-----------------------------------------------
# Require Maestrano
use lib $app_path . '/sso';

use MnoSsoUser;

1;
