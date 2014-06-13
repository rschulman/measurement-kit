#!/usr/bin/env python
# Public domain, 2013 Simone Basso <bassosimone@gmail.com>.

""" Test for IghtEchoServer """

import sys

sys.path.insert(0, "/usr/local/share/libight")

from _libight import EchoServer
from _libight import Poller

def main():
    """ Main function """
    poller = Poller()
    EchoServer(poller, 0, "127.0.0.1", "12345")
    poller.loop()

if __name__ == "__main__":
    main()