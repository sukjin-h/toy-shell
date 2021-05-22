# toy-shell
## Project #1 (Make Your Own Shell)

### OS: Ubuntu Linux

### I added a function to display username, hostname, cwd(current working directory). I changed the ㅠletter backgroung color of each item and exit while loop when entering "exit".


    char hostname[LEN_HOSTNAME + 1];
    memset(hostname, 0x00, sizeof(hostname));
    printf("\x1b[46musername\x1b[0m: %s\n", getpwuid(getuid())->pw_name);

    gethostname(hostname, LEN_HOSTNAME);
    printf("\x1b[43mhostname\x1b[0m: %s\n", hostname);

    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("\x1b[42mcwd\x1b[0m: %s\n", cwd);

> Display username, hostname, cwd(current working directory)
> Change letter background color username-> 46:Sky Blue, hostname-> 43:Yellow, cwd-> 42:Green 

    if (!strcmp(args[0], "exit")) {
		    break;
	}

> Exit While loop when entering "exit"
