# C detect-agent 

This project provides a robust C foundation for building a system monitoring agent, daemon, or other background service. It includes a flexible logging system and a simple file-based configuration parser, allowing you to focus on writing the core logic for your agent.
Features

   - File-based Configuration: Easily change settings by editing agent.conf.

   - Multi-level Logger: Logs messages to a file with different severity levels (DEBUG, INFO, WARN, ERROR, FATAL).

   - Automated Builds: A simple Makefile automates the entire compilation process.

Prerequisites

To build and run this project, you will need:

   - A C compiler (like gcc)

   - The make build tool

# Building the Agent

The included Makefile handles all compilation.

To build the project:

- make

To build and run the project in one step:

- make run

To clean up all compiled files:

- make clean

Configuration

The agent is configured via the agent.conf file, which must be in the same directory as the executable.

# agent.conf

log_level = INFO
log_file = agent.log

Parameters:

    log_level: Controls the verbosity of the logger.

        Valid options: DEBUG, INFO, WARN, ERROR, FATAL

    log_file: The path to the output log file where all messages will be written.

Usage

    Ensure agent.conf is configured and present in the root directory.

    Build the project with make.

    Run the executable:

    ./agent_test

    Check the output log file (agent.log by default) to see the agent's activity.

    cat agent.log


Roadmap

The agent is currently a skeleton. The core logic in main.c can be extended to perform useful tasks, such as:

    [ ] System Health Monitor: Periodically check CPU, RAM, and disk usage.

    [ ] Log File Watcher: Monitor other log files for specific keywords (e.g., "ERROR", "Failed").

    [ ] Service Health Checker: Attempt to connect to network ports to ensure services are online.
