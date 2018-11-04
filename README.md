# pam-logattempt

Pam module to log authentication attempts, including recording of attempted user/password/host.

## To compile

    $ sudo gcc -fPIC -DPIC -shared -rdynamic -o /usr/lib64/security/pam-logattempt.so pam-logattempt.c

## To enable

    $ sudo sed -i '/auth *sufficient *pam_unix.so nullok try_first_pass/a auth requisite pam-logattempt.so' /etc/pam.d/password-auth-ac
    
## To test

    $ ssh steve@localhost
    steve@localhost's password:topsecret
    Permission denied, please try again.
    steve@localhost's password:goodpassword
    Last failed login: Sun Nov  4 22:10:44 GMT 2018 from localhost on ssh:notty
    There were 7 failed login attempts since the last successful login.
    Last login: Sun Nov  4 21:54:08 2018 from localhost
    $
    
    # grep user=steve /var/log/messages
    Nov  4 22:10:42 localhost sshd[3777]: foo user=steve pass=topsecret host=localhost
    #
