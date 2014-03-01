/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of VerifyX509.xs. Do not edit this file, edit VerifyX509.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "VerifyX509.xs"
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#include <openssl/asn1.h>
#include <openssl/objects.h>
#include <openssl/bio.h>
#include <openssl/crypto.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/x509.h>
#include <openssl/x509v3.h>

typedef X509_STORE*  Crypt__OpenSSL__VerifyX509;
typedef X509*  Crypt__OpenSSL__X509;

static int verify_cb(int ok, X509_STORE_CTX *ctx) {
  if (!ok)
    switch (ctx->error) {
    case X509_V_ERR_CERT_HAS_EXPIRED:
 /* case X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT: */
    case X509_V_ERR_INVALID_CA:
    case X509_V_ERR_PATH_LENGTH_EXCEEDED:
    case X509_V_ERR_INVALID_PURPOSE:
    case X509_V_ERR_CRL_HAS_EXPIRED:
    case X509_V_ERR_CRL_NOT_YET_VALID:
    case X509_V_ERR_UNHANDLED_CRITICAL_EXTENSION:
      ok = 1;
      break;
    }
  return(ok);
}

static const char *ssl_error(void) {
  return ERR_error_string(ERR_get_error(), NULL);
}

static const char *ctx_error(X509_STORE_CTX *ctx) {
  return X509_verify_cert_error_string(ctx->error);
}

#line 53 "VerifyX509.c"
#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#ifndef dVAR
#  define dVAR		dNOOP
#endif


/* This stuff is not part of the API! You have been warned. */
#ifndef PERL_VERSION_DECIMAL
#  define PERL_VERSION_DECIMAL(r,v,s) (r*1000000 + v*1000 + s)
#endif
#ifndef PERL_DECIMAL_VERSION
#  define PERL_DECIMAL_VERSION \
	  PERL_VERSION_DECIMAL(PERL_REVISION,PERL_VERSION,PERL_SUBVERSION)
#endif
#ifndef PERL_VERSION_GE
#  define PERL_VERSION_GE(r,v,s) \
	  (PERL_DECIMAL_VERSION >= PERL_VERSION_DECIMAL(r,v,s))
#endif
#ifndef PERL_VERSION_LE
#  define PERL_VERSION_LE(r,v,s) \
	  (PERL_DECIMAL_VERSION <= PERL_VERSION_DECIMAL(r,v,s))
#endif

/* XS_INTERNAL is the explicit static-linkage variant of the default
 * XS macro.
 *
 * XS_EXTERNAL is the same as XS_INTERNAL except it does not include
 * "STATIC", ie. it exports XSUB symbols. You probably don't want that
 * for anything but the BOOT XSUB.
 *
 * See XSUB.h in core!
 */


/* TODO: This might be compatible further back than 5.10.0. */
#if PERL_VERSION_GE(5, 10, 0) && PERL_VERSION_LE(5, 15, 1)
#  undef XS_EXTERNAL
#  undef XS_INTERNAL
#  if defined(__CYGWIN__) && defined(USE_DYNAMIC_LOADING)
#    define XS_EXTERNAL(name) __declspec(dllexport) XSPROTO(name)
#    define XS_INTERNAL(name) STATIC XSPROTO(name)
#  endif
#  if defined(__SYMBIAN32__)
#    define XS_EXTERNAL(name) EXPORT_C XSPROTO(name)
#    define XS_INTERNAL(name) EXPORT_C STATIC XSPROTO(name)
#  endif
#  ifndef XS_EXTERNAL
#    if defined(HASATTRIBUTE_UNUSED) && !defined(__cplusplus)
#      define XS_EXTERNAL(name) void name(pTHX_ CV* cv __attribute__unused__)
#      define XS_INTERNAL(name) STATIC void name(pTHX_ CV* cv __attribute__unused__)
#    else
#      ifdef __cplusplus
#        define XS_EXTERNAL(name) extern "C" XSPROTO(name)
#        define XS_INTERNAL(name) static XSPROTO(name)
#      else
#        define XS_EXTERNAL(name) XSPROTO(name)
#        define XS_INTERNAL(name) STATIC XSPROTO(name)
#      endif
#    endif
#  endif
#endif

/* perl >= 5.10.0 && perl <= 5.15.1 */


/* The XS_EXTERNAL macro is used for functions that must not be static
 * like the boot XSUB of a module. If perl didn't have an XS_EXTERNAL
 * macro defined, the best we can do is assume XS is the same.
 * Dito for XS_INTERNAL.
 */
#ifndef XS_EXTERNAL
#  define XS_EXTERNAL(name) XS(name)
#endif
#ifndef XS_INTERNAL
#  define XS_INTERNAL(name) XS(name)
#endif

/* Now, finally, after all this mess, we want an ExtUtils::ParseXS
 * internal macro that we're free to redefine for varying linkage due
 * to the EXPORT_XSUB_SYMBOLS XS keyword. This is internal, use
 * XS_EXTERNAL(name) or XS_INTERNAL(name) in your code if you need to!
 */

#undef XS_EUPXS
#if defined(PERL_EUPXS_ALWAYS_EXPORT)
#  define XS_EUPXS(name) XS_EXTERNAL(name)
#else
   /* default to internal */
#  define XS_EUPXS(name) XS_INTERNAL(name)
#endif

#ifndef PERL_ARGS_ASSERT_CROAK_XS_USAGE
#define PERL_ARGS_ASSERT_CROAK_XS_USAGE assert(cv); assert(params)

/* prototype to pass -Wmissing-prototypes */
STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params);

STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params)
{
    const GV *const gv = CvGV(cv);

    PERL_ARGS_ASSERT_CROAK_XS_USAGE;

    if (gv) {
        const char *const gvname = GvNAME(gv);
        const HV *const stash = GvSTASH(gv);
        const char *const hvname = stash ? HvNAME(stash) : NULL;

        if (hvname)
            Perl_croak(aTHX_ "Usage: %s::%s(%s)", hvname, gvname, params);
        else
            Perl_croak(aTHX_ "Usage: %s(%s)", gvname, params);
    } else {
        /* Pants. I don't think that it should be possible to get here. */
        Perl_croak(aTHX_ "Usage: CODE(0x%"UVxf")(%s)", PTR2UV(cv), params);
    }
}
#undef  PERL_ARGS_ASSERT_CROAK_XS_USAGE

#ifdef PERL_IMPLICIT_CONTEXT
#define croak_xs_usage(a,b)    S_croak_xs_usage(aTHX_ a,b)
#else
#define croak_xs_usage        S_croak_xs_usage
#endif

#endif

/* NOTE: the prototype of newXSproto() is different in versions of perls,
 * so we define a portable version of newXSproto()
 */
#ifdef newXS_flags
#define newXSproto_portable(name, c_impl, file, proto) newXS_flags(name, c_impl, file, proto, 0)
#else
#define newXSproto_portable(name, c_impl, file, proto) (PL_Sv=(SV*)newXS(name, c_impl, file), sv_setpv(PL_Sv, proto), (CV*)PL_Sv)
#endif /* !defined(newXS_flags) */

#line 195 "VerifyX509.c"

XS_EUPXS(XS_Crypt__OpenSSL__VerifyX509_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Crypt__OpenSSL__VerifyX509_new)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "class, cafile_str");
    {
	SV *	class = ST(0)
;
	SV *	cafile_str = ST(1)
;
#line 59 "VerifyX509.xs"
  int i = 1;
  X509_LOOKUP *lookup = NULL;
  STRLEN len;
  char *cafile;

#line 214 "VerifyX509.c"
	Crypt__OpenSSL__VerifyX509	RETVAL;
#line 66 "VerifyX509.xs"
  (void) SvPV_nolen(class);

  RETVAL = X509_STORE_new();
  if (RETVAL == NULL)
    croak("failure to allocate x509 store: %s", ssl_error());

  X509_STORE_set_verify_cb_func(RETVAL,verify_cb);

  /* load CA file given */
  lookup = X509_STORE_add_lookup(RETVAL, X509_LOOKUP_file());
  if (lookup == NULL) 
    croak("failure to add file lookup to store: %s", ssl_error());

  cafile = SvPV(cafile_str, len);
  i = X509_LOOKUP_load_file(lookup, cafile, X509_FILETYPE_PEM);

  if (!i)
    croak("load CA cert: %s", ssl_error());

  /* default hash_dir lookup */
  lookup = X509_STORE_add_lookup(RETVAL,X509_LOOKUP_hash_dir());
  if (lookup == NULL) 
    croak("failure to add hash_dir lookup to store: %s", ssl_error());

  X509_LOOKUP_add_dir(lookup,NULL,X509_FILETYPE_DEFAULT);  

  ERR_clear_error();

#line 245 "VerifyX509.c"
	ST(0) = sv_newmortal();
	sv_setref_pv(ST(0), "Crypt::OpenSSL::VerifyX509", (void*)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Crypt__OpenSSL__VerifyX509_verify); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Crypt__OpenSSL__VerifyX509_verify)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "store, x509");
    {
	Crypt__OpenSSL__VerifyX509	store;
	Crypt__OpenSSL__X509	x509;
#line 104 "VerifyX509.xs"
  X509_STORE_CTX *csc;

#line 265 "VerifyX509.c"
	int	RETVAL;
	dXSTARG;

	if (SvROK(ST(0)) && sv_derived_from(ST(0), "Crypt::OpenSSL::VerifyX509")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    store = INT2PTR(Crypt__OpenSSL__VerifyX509,tmp);
	}
	else
	    Perl_croak(aTHX_ "%s: %s is not of type %s",
			"Crypt::OpenSSL::VerifyX509::verify",
			"store", "Crypt::OpenSSL::VerifyX509")
;

	if (SvROK(ST(1)) && sv_derived_from(ST(1), "Crypt::OpenSSL::X509")) {
	    IV tmp = SvIV((SV*)SvRV(ST(1)));
	    x509 = INT2PTR(Crypt__OpenSSL__X509,tmp);
	}
	else
	    Perl_croak(aTHX_ "%s: %s is not of type %s",
			"Crypt::OpenSSL::VerifyX509::verify",
			"x509", "Crypt::OpenSSL::X509")
;
#line 108 "VerifyX509.xs"
  if (x509 == NULL)
    croak("no cert to verify");

  csc = X509_STORE_CTX_new();
  if (csc == NULL)
    croak("csc new: %s", ssl_error());

  X509_STORE_set_flags(store, 0);

  if (!X509_STORE_CTX_init(csc,store,x509,NULL))
    croak("store ctx init: %s", ssl_error());

  RETVAL = X509_verify_cert(csc);
  X509_STORE_CTX_free(csc);

  if (!RETVAL)
    croak("verify: %s", ctx_error(csc));

#line 307 "VerifyX509.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Crypt__OpenSSL__VerifyX509_DESTROY); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Crypt__OpenSSL__VerifyX509_DESTROY)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "store");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	Crypt__OpenSSL__VerifyX509	store;

	if (SvROK(ST(0))) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    store = INT2PTR(Crypt__OpenSSL__VerifyX509,tmp);
	}
	else
	    Perl_croak(aTHX_ "%s: %s is not a reference",
			"Crypt::OpenSSL::VerifyX509::DESTROY",
			"store")
;
#line 135 "VerifyX509.xs"
  if (store) X509_STORE_free(store); store = 0;
#line 336 "VerifyX509.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Crypt__OpenSSL__VerifyX509___X509_cleanup); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Crypt__OpenSSL__VerifyX509___X509_cleanup)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "void");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 141 "VerifyX509.xs"
  CRYPTO_cleanup_all_ex_data();
  ERR_free_strings();
  ERR_remove_state(0);
  EVP_cleanup();
#line 357 "VerifyX509.c"
	PUTBACK;
	return;
    }
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Crypt__OpenSSL__VerifyX509); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Crypt__OpenSSL__VerifyX509)
{
    dVAR; dXSARGS;
#if (PERL_REVISION == 5 && PERL_VERSION < 9)
    char* file = __FILE__;
#else
    const char* file = __FILE__;
#endif

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
#ifdef XS_APIVERSION_BOOTCHECK
    XS_APIVERSION_BOOTCHECK;
#endif
    XS_VERSION_BOOTCHECK;

        newXS("Crypt::OpenSSL::VerifyX509::new", XS_Crypt__OpenSSL__VerifyX509_new, file);
        newXS("Crypt::OpenSSL::VerifyX509::verify", XS_Crypt__OpenSSL__VerifyX509_verify, file);
        newXS("Crypt::OpenSSL::VerifyX509::DESTROY", XS_Crypt__OpenSSL__VerifyX509_DESTROY, file);
        newXS("Crypt::OpenSSL::VerifyX509::__X509_cleanup", XS_Crypt__OpenSSL__VerifyX509___X509_cleanup, file);

    /* Initialisation Section */

#line 48 "VerifyX509.xs"
  ERR_load_crypto_strings();
  ERR_load_ERR_strings();
  OpenSSL_add_all_algorithms();

#line 395 "VerifyX509.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}
