# Web Requests

## Category

Forensics

## Level

Medium

## Description

The pcap attached contains many HTTP requests. All requests use the same version of HTTP in this
pcap.

What is the total number of HTTP requests that are made?

Submit your answer inside of `casual{}`. For example, if there were 23 requests made, then the flag
would be `casual{23}`.

## Hint

Maybe some other ports besides port 80 are making HTTP requests.

## Files to upload to CTFd

* web_traffic.pcap

## Solution

There are HTTP servers on port 80 and port 21. However, Wireshark will display port 21 traffic as
FTP, so one cannot simply search using the `http` filter. Instead, one strategy that one can use is
to search for the bytes that are present only in HTTP requests. One such sequence of bytes is 48,
54, 54, 50, 2f, 31, 2e, 31, 0d, 0a, which is the string "HTTP/1.1\r\n" (the description says that
all requests use the same version of HTTP, and it is trivial to find the version by looking at any
HTTP request). The filter `frame contains 48:54:54:50:2f:31:2e:31:0d:0a` will display all HTTP
requests.

The flag for the default pcap file is `FLAG{40}`.

## Build

The Mayan EDMS and Mattermost web applications were used to generate the HTTP traffic. In addition,
Portainer was installed to generate HTTPS traffic as a distraction for competitors. These
applications were installed via Docker:

* Mayan EDMS - https://docs.mayan-edms.com/chapters/docker/install_docker_compose.html#docker-compose-install
* Mattermost - https://docs.mattermost.com/install/install-docker.html#deploy-mattermost-on-docker-for-production-use
* Portainer - https://docs.portainer.io/start/install-ce/server/docker/linux

Mayan was configured to run on port 80, Mattermost on port 21, and Portainer on port 9443. After
installation and initial configuration, Wireshark was run on the server machine, and several pages
from each of the websites were accessed simultaneously from different machines.
