# Lunch

## Category

Forensics

## Level

Easy

## Description

Some employees are at Sandals Labs are discussing their lunch plans tomorrow.

Where are they going to go for lunch and what time?

Submit you answer in the format `casual{<location>-<hour>:<minute>[am|pm]}`. For example, if the employees are
planning to go to the restaurant Seafood House at 2 pm, then the flag would be `casual{Seafood House-2:00pm}`.

## Hint

Look at HTTP requests to `/api/v4/posts`.

## Files to upload to CTFd

* lunch.pcap

## Solution

Messages sent by the employees are in HTTP POST requests to `/api/v4/posts`. The Wireshark filter
`http.request.url=="/api/v4/posts"` will show only those requests. In each of these requests is a
JSON object that has a `message` key that contains a message sent by an employee. Reading through
all the messages will reveal the lunch location and time.

The flag for the default pcap file is `casual{First Street Alehouse-12:00pm}`.

## Build

The application used to generate the HTTP traffic is Mattermost, which is a chat application. The
easiest way to install Mattermost is to deploy via Docker: https://docs.mattermost.com/install/install-docker.html#deploy-mattermost-on-docker-for-production-use.

Once Mattermost is running, create a team and add a few accounts to the team (3 accounts were created
for the default pcap file). Logon to Mattermost from different IPs (this can be done by using
different devices or creating VMs using bridged mode) to simulate users using different computers.

Back on the machine running the Mattermost server, start Wireshark. On each of the client machines,
send messages simulating employees planning for lunch.
