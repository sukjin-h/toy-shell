# toy-shell
# Project #1 (Make Your Own Shell)

# OS: Ubuntu Linux

# I added a function to display host name, user name, cwd. I changed the color of each item and exit when entering "EXIT".

<!-- Bullet list -->

display host name, user name, cwd:
    char hostname[LEN_HOSTNAME + 1];
    memset(hostname, 0x00, sizeof(hostname));
    printf("\x1b[46musername\x1b[0m: %s\n", getpwuid(getuid())->pw_name);

    gethostname(hostname, LEN_HOSTNAME);
    printf("\x1b[43mhostname\x1b[0m: %s\n", hostname);

    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("\x1b[42mcwd\x1b[0m: %s\n", cwd);



