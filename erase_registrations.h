//-------------------------------------------------------------------------------
//
// erase_registrations.h - Command line tool to transmit
//                         a SIP REGISTER request which erases all
//                         registrations for a UA.
//
//    Copyright (C) 2006  Mark D. Collier/Mark O'Brien
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
//
//   Author: Mark D. Collier/Mark O'Brien - 02/24/2006  v1.0
//         www.securelogix.com - mark.collier@securelogix.com
//         www.hackingexposedvoip.com
//
//-------------------------------------------------------------------------------

#ifndef __ERASE_REGISTRATIONS_H
#define __ERASE_REGISTRATIONS_H

#include <libnet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h> 
#include <linux/sockios.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <sys/time.h>
#include <unistd.h>

#include <signal.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define __ERASE_REGISTRATIONS_VERSION  "erase_registrations - Version 1.0"
#define __ERASE_REGISTRATIONS_DATE     "                      Feb. 24, 2006"

// Not really the maximum, but close to the Layer 2 limit once UDP, IP, and Ethernet headers
// are accounted for. The max Ethernet packet is about 1518 bytes.

#define	__ERASE_REGISTRATIONS_SIP_PAYLOAD_LEN_MAX        1400

char sipPayload[__ERASE_REGISTRATIONS_SIP_PAYLOAD_LEN_MAX];
char errbuf[LIBNET_ERRBUF_SIZE];
char destIPv4AddrDotted[16];
char srcIPv4AddrDotted[16];

int opt;
int bytesWritten;
int ipPacketSize;
int destIPv4Addr;
int domain;
int sipPayloadSize              = 0;
int sockfd                      = 0;
int srcPort                     = 9;    // default to well-known port to discard packet
int destPort                    = 5060;

unsigned int srcIPv4Addr        = 0;

libnet_t *l                     = NULL;

libnet_ptag_t udp_tag           = 0;
libnet_ptag_t ip_tag            = 0;

char *psDevice                  = NULL;

char *psDestIPv4Addr            = NULL;
char *psTempIPv4Addr            = NULL;
char *psSrcIPv4Addr             = NULL;
char *psBranch                  = NULL;
char *psDomain                  = NULL;
char *psCallID                  = NULL;
char *psFromTag                 = "";
char *psUser                    = "";

unsigned char *ipStr            = NULL;  // to enable access of host IP by bytes

bool bVerbose                   = false;

struct ifreq ifreq;
struct sockaddr_in *saptr       = NULL;

void  catch_signals  ( int signo );
void  CleanupAndExit ( int status );
void  usage ( );

#endif  //  __ERASE_REGISTRATIONS_H
