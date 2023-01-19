/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         pcap_parse
#define yylex           pcap_lex
#define yyerror         pcap_error
#define yydebug         pcap_debug
#define yynerrs         pcap_nerrs
#define yylval          pcap_lval
#define yychar          pcap_char

/* First part of user prologue.  */
#line 1 "grammar.y"

/*
 * Copyright (c) 1988, 1989, 1990, 1991, 1992, 1993, 1994, 1995, 1996
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that: (1) source code distributions
 * retain the above copyright notice and this paragraph in its entirety, (2)
 * distributions including binary code include the above copyright notice and
 * this paragraph in its entirety in the documentation or other materials
 * provided with the distribution, and (3) all advertising materials mentioning
 * features or use of this software display the following acknowledgement:
 * ``This product includes software developed by the University of California,
 * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of
 * the University nor the names of its contributors may be used to endorse
 * or promote products derived from this software without specific prior
 * written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 */
#ifndef lint
static const char rcsid[] _U_ =
    "@(#) $Header: /tcpdump/master/libpcap/grammar.y,v 1.101 2007-11-18 02:03:52 guy Exp $ (LBL)";
#endif

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef WIN32
#include <pcap-stdinc.h>
#else /* WIN32 */
#include <sys/types.h>
#include <sys/socket.h>
#endif /* WIN32 */

#include <stdlib.h>

#ifndef WIN32
#if __STDC__
struct mbuf;
struct rtentry;
#endif

#include <netinet/in.h>
#include <arpa/inet.h>
#endif /* WIN32 */

#include <stdio.h>

#include "pcap-int.h"

#include "gencode.h"
#ifdef HAVE_NET_PFVAR_H
#include <net/if.h>
#include <net/pfvar.h>
#include <net/if_pflog.h>
#endif
#include "ieee80211.h"
#include <pcap/namedb.h>

#ifdef HAVE_OS_PROTO_H
#include "os-proto.h"
#endif

#define QSET(q, p, d, a) (q).proto = (p),\
			 (q).dir = (d),\
			 (q).addr = (a)

struct tok {
	int v;			/* value */
	const char *s;		/* string */
};

static const struct tok ieee80211_types[] = {
	{ IEEE80211_FC0_TYPE_DATA, "data" },
	{ IEEE80211_FC0_TYPE_MGT, "mgt" },
	{ IEEE80211_FC0_TYPE_MGT, "management" },
	{ IEEE80211_FC0_TYPE_CTL, "ctl" },
	{ IEEE80211_FC0_TYPE_CTL, "control" },
	{ 0, NULL }
};
static const struct tok ieee80211_mgt_subtypes[] = {
	{ IEEE80211_FC0_SUBTYPE_ASSOC_REQ, "assocreq" },
	{ IEEE80211_FC0_SUBTYPE_ASSOC_REQ, "assoc-req" },
	{ IEEE80211_FC0_SUBTYPE_ASSOC_RESP, "assocresp" },
	{ IEEE80211_FC0_SUBTYPE_ASSOC_RESP, "assoc-resp" },
	{ IEEE80211_FC0_SUBTYPE_REASSOC_REQ, "reassocreq" },
	{ IEEE80211_FC0_SUBTYPE_REASSOC_REQ, "reassoc-req" },
	{ IEEE80211_FC0_SUBTYPE_REASSOC_RESP, "reassocresp" },
	{ IEEE80211_FC0_SUBTYPE_REASSOC_RESP, "reassoc-resp" },
	{ IEEE80211_FC0_SUBTYPE_PROBE_REQ, "probereq" },
	{ IEEE80211_FC0_SUBTYPE_PROBE_REQ, "probe-req" },
	{ IEEE80211_FC0_SUBTYPE_PROBE_RESP, "proberesp" },
	{ IEEE80211_FC0_SUBTYPE_PROBE_RESP, "probe-resp" },
	{ IEEE80211_FC0_SUBTYPE_BEACON, "beacon" },
	{ IEEE80211_FC0_SUBTYPE_ATIM, "atim" },
	{ IEEE80211_FC0_SUBTYPE_DISASSOC, "disassoc" },
	{ IEEE80211_FC0_SUBTYPE_DISASSOC, "disassociation" },
	{ IEEE80211_FC0_SUBTYPE_AUTH, "auth" },
	{ IEEE80211_FC0_SUBTYPE_AUTH, "authentication" },
	{ IEEE80211_FC0_SUBTYPE_DEAUTH, "deauth" },
	{ IEEE80211_FC0_SUBTYPE_DEAUTH, "deauthentication" },
	{ 0, NULL }
};
static const struct tok ieee80211_ctl_subtypes[] = {
	{ IEEE80211_FC0_SUBTYPE_PS_POLL, "ps-poll" },
	{ IEEE80211_FC0_SUBTYPE_RTS, "rts" },
	{ IEEE80211_FC0_SUBTYPE_CTS, "cts" },
	{ IEEE80211_FC0_SUBTYPE_ACK, "ack" },
	{ IEEE80211_FC0_SUBTYPE_CF_END, "cf-end" },
	{ IEEE80211_FC0_SUBTYPE_CF_END_ACK, "cf-end-ack" },
	{ 0, NULL }
};
static const struct tok ieee80211_data_subtypes[] = {
	{ IEEE80211_FC0_SUBTYPE_DATA, "data" },
	{ IEEE80211_FC0_SUBTYPE_CF_ACK, "data-cf-ack" },
	{ IEEE80211_FC0_SUBTYPE_CF_POLL, "data-cf-poll" },
	{ IEEE80211_FC0_SUBTYPE_CF_ACPL, "data-cf-ack-poll" },
	{ IEEE80211_FC0_SUBTYPE_NODATA, "null" },
	{ IEEE80211_FC0_SUBTYPE_NODATA_CF_ACK, "cf-ack" },
	{ IEEE80211_FC0_SUBTYPE_NODATA_CF_POLL, "cf-poll"  },
	{ IEEE80211_FC0_SUBTYPE_NODATA_CF_ACPL, "cf-ack-poll" },
	{ IEEE80211_FC0_SUBTYPE_QOS|IEEE80211_FC0_SUBTYPE_DATA, "qos-data" },
	{ IEEE80211_FC0_SUBTYPE_QOS|IEEE80211_FC0_SUBTYPE_CF_ACK, "qos-data-cf-ack" },
	{ IEEE80211_FC0_SUBTYPE_QOS|IEEE80211_FC0_SUBTYPE_CF_POLL, "qos-data-cf-poll" },
	{ IEEE80211_FC0_SUBTYPE_QOS|IEEE80211_FC0_SUBTYPE_CF_ACPL, "qos-data-cf-ack-poll" },
	{ IEEE80211_FC0_SUBTYPE_QOS|IEEE80211_FC0_SUBTYPE_NODATA, "qos" },
	{ IEEE80211_FC0_SUBTYPE_QOS|IEEE80211_FC0_SUBTYPE_NODATA_CF_POLL, "qos-cf-poll" },
	{ IEEE80211_FC0_SUBTYPE_QOS|IEEE80211_FC0_SUBTYPE_NODATA_CF_ACPL, "qos-cf-ack-poll" },
	{ 0, NULL }
};
struct type2tok {
	int type;
	const struct tok *tok;
};
static const struct type2tok ieee80211_type_subtypes[] = {
	{ IEEE80211_FC0_TYPE_MGT, ieee80211_mgt_subtypes },
	{ IEEE80211_FC0_TYPE_CTL, ieee80211_ctl_subtypes },
	{ IEEE80211_FC0_TYPE_DATA, ieee80211_data_subtypes },
	{ 0, NULL }
};

static int
str2tok(const char *str, const struct tok *toks)
{
	int i;

	for (i = 0; toks[i].s != NULL; i++) {
		if (pcap_strcasecmp(toks[i].s, str) == 0)
			return (toks[i].v);
	}
	return (-1);
}

int n_errors = 0;

static struct qual qerr = { Q_UNDEF, Q_UNDEF, Q_UNDEF, Q_UNDEF };

static void
yyerror(const char *msg)
{
	++n_errors;
	bpf_error("%s", msg);
	/* NOTREACHED */
}

#ifdef NEED_YYPARSE_WRAPPER
int yyparse(void);

int
pcap_parse()
{
	return (yyparse());
}
#endif

#ifdef HAVE_NET_PFVAR_H
static int
pfreason_to_num(const char *reason)
{
	const char *reasons[] = PFRES_NAMES;
	int i;

	for (i = 0; reasons[i]; i++) {
		if (pcap_strcasecmp(reason, reasons[i]) == 0)
			return (i);
	}
	bpf_error("unknown PF reason");
	/*NOTREACHED*/
}

static int
pfaction_to_num(const char *action)
{
	if (pcap_strcasecmp(action, "pass") == 0 ||
	    pcap_strcasecmp(action, "accept") == 0)
		return (PF_PASS);
	else if (pcap_strcasecmp(action, "drop") == 0 ||
		pcap_strcasecmp(action, "block") == 0)
		return (PF_DROP);
#if HAVE_PF_NAT_THROUGH_PF_NORDR
	else if (pcap_strcasecmp(action, "rdr") == 0)
		return (PF_RDR);
	else if (pcap_strcasecmp(action, "nat") == 0)
		return (PF_NAT);
	else if (pcap_strcasecmp(action, "binat") == 0)
		return (PF_BINAT);
	else if (pcap_strcasecmp(action, "nordr") == 0)
		return (PF_NORDR);
#endif
	else {
		bpf_error("unknown PF action");
		/*NOTREACHED*/
	}
}
#else /* !HAVE_NET_PFVAR_H */
static int
pfreason_to_num(const char *reason)
{
	bpf_error("libpcap was compiled on a machine without pf support");
	/*NOTREACHED*/

	/* this is to make the VC compiler happy */
	return -1;
}

static int
pfaction_to_num(const char *action)
{
	bpf_error("libpcap was compiled on a machine without pf support");
	/*NOTREACHED*/

	/* this is to make the VC compiler happy */
	return -1;
}
#endif /* HAVE_NET_PFVAR_H */

#line 319 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_PCAP_Y_TAB_H_INCLUDED
# define YY_PCAP_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int pcap_debug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    DST = 258,                     /* DST  */
    SRC = 259,                     /* SRC  */
    HOST = 260,                    /* HOST  */
    GATEWAY = 261,                 /* GATEWAY  */
    NET = 262,                     /* NET  */
    NETMASK = 263,                 /* NETMASK  */
    PORT = 264,                    /* PORT  */
    PORTRANGE = 265,               /* PORTRANGE  */
    LESS = 266,                    /* LESS  */
    GREATER = 267,                 /* GREATER  */
    PROTO = 268,                   /* PROTO  */
    PROTOCHAIN = 269,              /* PROTOCHAIN  */
    CBYTE = 270,                   /* CBYTE  */
    ARP = 271,                     /* ARP  */
    RARP = 272,                    /* RARP  */
    IP = 273,                      /* IP  */
    SCTP = 274,                    /* SCTP  */
    TCP = 275,                     /* TCP  */
    UDP = 276,                     /* UDP  */
    ICMP = 277,                    /* ICMP  */
    IGMP = 278,                    /* IGMP  */
    IGRP = 279,                    /* IGRP  */
    PIM = 280,                     /* PIM  */
    VRRP = 281,                    /* VRRP  */
    CARP = 282,                    /* CARP  */
    ATALK = 283,                   /* ATALK  */
    AARP = 284,                    /* AARP  */
    DECNET = 285,                  /* DECNET  */
    LAT = 286,                     /* LAT  */
    SCA = 287,                     /* SCA  */
    MOPRC = 288,                   /* MOPRC  */
    MOPDL = 289,                   /* MOPDL  */
    TK_BROADCAST = 290,            /* TK_BROADCAST  */
    TK_MULTICAST = 291,            /* TK_MULTICAST  */
    NUM = 292,                     /* NUM  */
    INBOUND = 293,                 /* INBOUND  */
    OUTBOUND = 294,                /* OUTBOUND  */
    PF_IFNAME = 295,               /* PF_IFNAME  */
    PF_RSET = 296,                 /* PF_RSET  */
    PF_RNR = 297,                  /* PF_RNR  */
    PF_SRNR = 298,                 /* PF_SRNR  */
    PF_REASON = 299,               /* PF_REASON  */
    PF_ACTION = 300,               /* PF_ACTION  */
    TYPE = 301,                    /* TYPE  */
    SUBTYPE = 302,                 /* SUBTYPE  */
    DIR = 303,                     /* DIR  */
    ADDR1 = 304,                   /* ADDR1  */
    ADDR2 = 305,                   /* ADDR2  */
    ADDR3 = 306,                   /* ADDR3  */
    ADDR4 = 307,                   /* ADDR4  */
    RA = 308,                      /* RA  */
    TA = 309,                      /* TA  */
    LINK = 310,                    /* LINK  */
    GEQ = 311,                     /* GEQ  */
    LEQ = 312,                     /* LEQ  */
    NEQ = 313,                     /* NEQ  */
    ID = 314,                      /* ID  */
    EID = 315,                     /* EID  */
    HID = 316,                     /* HID  */
    HID6 = 317,                    /* HID6  */
    AID = 318,                     /* AID  */
    LSH = 319,                     /* LSH  */
    RSH = 320,                     /* RSH  */
    LEN = 321,                     /* LEN  */
    IPV6 = 322,                    /* IPV6  */
    ICMPV6 = 323,                  /* ICMPV6  */
    AH = 324,                      /* AH  */
    ESP = 325,                     /* ESP  */
    VLAN = 326,                    /* VLAN  */
    MPLS = 327,                    /* MPLS  */
    PPPOED = 328,                  /* PPPOED  */
    PPPOES = 329,                  /* PPPOES  */
    ISO = 330,                     /* ISO  */
    ESIS = 331,                    /* ESIS  */
    CLNP = 332,                    /* CLNP  */
    ISIS = 333,                    /* ISIS  */
    L1 = 334,                      /* L1  */
    L2 = 335,                      /* L2  */
    IIH = 336,                     /* IIH  */
    LSP = 337,                     /* LSP  */
    SNP = 338,                     /* SNP  */
    CSNP = 339,                    /* CSNP  */
    PSNP = 340,                    /* PSNP  */
    STP = 341,                     /* STP  */
    IPX = 342,                     /* IPX  */
    NETBEUI = 343,                 /* NETBEUI  */
    LANE = 344,                    /* LANE  */
    LLC = 345,                     /* LLC  */
    METAC = 346,                   /* METAC  */
    BCC = 347,                     /* BCC  */
    SC = 348,                      /* SC  */
    ILMIC = 349,                   /* ILMIC  */
    OAMF4EC = 350,                 /* OAMF4EC  */
    OAMF4SC = 351,                 /* OAMF4SC  */
    OAM = 352,                     /* OAM  */
    OAMF4 = 353,                   /* OAMF4  */
    CONNECTMSG = 354,              /* CONNECTMSG  */
    METACONNECT = 355,             /* METACONNECT  */
    VPI = 356,                     /* VPI  */
    VCI = 357,                     /* VCI  */
    RADIO = 358,                   /* RADIO  */
    FISU = 359,                    /* FISU  */
    LSSU = 360,                    /* LSSU  */
    MSU = 361,                     /* MSU  */
    SIO = 362,                     /* SIO  */
    OPC = 363,                     /* OPC  */
    DPC = 364,                     /* DPC  */
    SLS = 365,                     /* SLS  */
    OR = 366,                      /* OR  */
    AND = 367,                     /* AND  */
    UMINUS = 368                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define DST 258
#define SRC 259
#define HOST 260
#define GATEWAY 261
#define NET 262
#define NETMASK 263
#define PORT 264
#define PORTRANGE 265
#define LESS 266
#define GREATER 267
#define PROTO 268
#define PROTOCHAIN 269
#define CBYTE 270
#define ARP 271
#define RARP 272
#define IP 273
#define SCTP 274
#define TCP 275
#define UDP 276
#define ICMP 277
#define IGMP 278
#define IGRP 279
#define PIM 280
#define VRRP 281
#define CARP 282
#define ATALK 283
#define AARP 284
#define DECNET 285
#define LAT 286
#define SCA 287
#define MOPRC 288
#define MOPDL 289
#define TK_BROADCAST 290
#define TK_MULTICAST 291
#define NUM 292
#define INBOUND 293
#define OUTBOUND 294
#define PF_IFNAME 295
#define PF_RSET 296
#define PF_RNR 297
#define PF_SRNR 298
#define PF_REASON 299
#define PF_ACTION 300
#define TYPE 301
#define SUBTYPE 302
#define DIR 303
#define ADDR1 304
#define ADDR2 305
#define ADDR3 306
#define ADDR4 307
#define RA 308
#define TA 309
#define LINK 310
#define GEQ 311
#define LEQ 312
#define NEQ 313
#define ID 314
#define EID 315
#define HID 316
#define HID6 317
#define AID 318
#define LSH 319
#define RSH 320
#define LEN 321
#define IPV6 322
#define ICMPV6 323
#define AH 324
#define ESP 325
#define VLAN 326
#define MPLS 327
#define PPPOED 328
#define PPPOES 329
#define ISO 330
#define ESIS 331
#define CLNP 332
#define ISIS 333
#define L1 334
#define L2 335
#define IIH 336
#define LSP 337
#define SNP 338
#define CSNP 339
#define PSNP 340
#define STP 341
#define IPX 342
#define NETBEUI 343
#define LANE 344
#define LLC 345
#define METAC 346
#define BCC 347
#define SC 348
#define ILMIC 349
#define OAMF4EC 350
#define OAMF4SC 351
#define OAM 352
#define OAMF4 353
#define CONNECTMSG 354
#define METACONNECT 355
#define VPI 356
#define VCI 357
#define RADIO 358
#define FISU 359
#define LSSU 360
#define MSU 361
#define SIO 362
#define OPC 363
#define DPC 364
#define SLS 365
#define OR 366
#define AND 367
#define UMINUS 368

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 242 "grammar.y"

	int i;
	bpf_u_int32 h;
	u_char *e;
	char *s;
	struct stmt *stmt;
	struct arth *a;
	struct {
		struct qual q;
		int atmfieldtype;
		int mtp3fieldtype;
		struct block *b;
	} blk;
	struct block *rblk;

#line 614 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE pcap_lval;


int pcap_parse (void);


#endif /* !YY_PCAP_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DST = 3,                        /* DST  */
  YYSYMBOL_SRC = 4,                        /* SRC  */
  YYSYMBOL_HOST = 5,                       /* HOST  */
  YYSYMBOL_GATEWAY = 6,                    /* GATEWAY  */
  YYSYMBOL_NET = 7,                        /* NET  */
  YYSYMBOL_NETMASK = 8,                    /* NETMASK  */
  YYSYMBOL_PORT = 9,                       /* PORT  */
  YYSYMBOL_PORTRANGE = 10,                 /* PORTRANGE  */
  YYSYMBOL_LESS = 11,                      /* LESS  */
  YYSYMBOL_GREATER = 12,                   /* GREATER  */
  YYSYMBOL_PROTO = 13,                     /* PROTO  */
  YYSYMBOL_PROTOCHAIN = 14,                /* PROTOCHAIN  */
  YYSYMBOL_CBYTE = 15,                     /* CBYTE  */
  YYSYMBOL_ARP = 16,                       /* ARP  */
  YYSYMBOL_RARP = 17,                      /* RARP  */
  YYSYMBOL_IP = 18,                        /* IP  */
  YYSYMBOL_SCTP = 19,                      /* SCTP  */
  YYSYMBOL_TCP = 20,                       /* TCP  */
  YYSYMBOL_UDP = 21,                       /* UDP  */
  YYSYMBOL_ICMP = 22,                      /* ICMP  */
  YYSYMBOL_IGMP = 23,                      /* IGMP  */
  YYSYMBOL_IGRP = 24,                      /* IGRP  */
  YYSYMBOL_PIM = 25,                       /* PIM  */
  YYSYMBOL_VRRP = 26,                      /* VRRP  */
  YYSYMBOL_CARP = 27,                      /* CARP  */
  YYSYMBOL_ATALK = 28,                     /* ATALK  */
  YYSYMBOL_AARP = 29,                      /* AARP  */
  YYSYMBOL_DECNET = 30,                    /* DECNET  */
  YYSYMBOL_LAT = 31,                       /* LAT  */
  YYSYMBOL_SCA = 32,                       /* SCA  */
  YYSYMBOL_MOPRC = 33,                     /* MOPRC  */
  YYSYMBOL_MOPDL = 34,                     /* MOPDL  */
  YYSYMBOL_TK_BROADCAST = 35,              /* TK_BROADCAST  */
  YYSYMBOL_TK_MULTICAST = 36,              /* TK_MULTICAST  */
  YYSYMBOL_NUM = 37,                       /* NUM  */
  YYSYMBOL_INBOUND = 38,                   /* INBOUND  */
  YYSYMBOL_OUTBOUND = 39,                  /* OUTBOUND  */
  YYSYMBOL_PF_IFNAME = 40,                 /* PF_IFNAME  */
  YYSYMBOL_PF_RSET = 41,                   /* PF_RSET  */
  YYSYMBOL_PF_RNR = 42,                    /* PF_RNR  */
  YYSYMBOL_PF_SRNR = 43,                   /* PF_SRNR  */
  YYSYMBOL_PF_REASON = 44,                 /* PF_REASON  */
  YYSYMBOL_PF_ACTION = 45,                 /* PF_ACTION  */
  YYSYMBOL_TYPE = 46,                      /* TYPE  */
  YYSYMBOL_SUBTYPE = 47,                   /* SUBTYPE  */
  YYSYMBOL_DIR = 48,                       /* DIR  */
  YYSYMBOL_ADDR1 = 49,                     /* ADDR1  */
  YYSYMBOL_ADDR2 = 50,                     /* ADDR2  */
  YYSYMBOL_ADDR3 = 51,                     /* ADDR3  */
  YYSYMBOL_ADDR4 = 52,                     /* ADDR4  */
  YYSYMBOL_RA = 53,                        /* RA  */
  YYSYMBOL_TA = 54,                        /* TA  */
  YYSYMBOL_LINK = 55,                      /* LINK  */
  YYSYMBOL_GEQ = 56,                       /* GEQ  */
  YYSYMBOL_LEQ = 57,                       /* LEQ  */
  YYSYMBOL_NEQ = 58,                       /* NEQ  */
  YYSYMBOL_ID = 59,                        /* ID  */
  YYSYMBOL_EID = 60,                       /* EID  */
  YYSYMBOL_HID = 61,                       /* HID  */
  YYSYMBOL_HID6 = 62,                      /* HID6  */
  YYSYMBOL_AID = 63,                       /* AID  */
  YYSYMBOL_LSH = 64,                       /* LSH  */
  YYSYMBOL_RSH = 65,                       /* RSH  */
  YYSYMBOL_LEN = 66,                       /* LEN  */
  YYSYMBOL_IPV6 = 67,                      /* IPV6  */
  YYSYMBOL_ICMPV6 = 68,                    /* ICMPV6  */
  YYSYMBOL_AH = 69,                        /* AH  */
  YYSYMBOL_ESP = 70,                       /* ESP  */
  YYSYMBOL_VLAN = 71,                      /* VLAN  */
  YYSYMBOL_MPLS = 72,                      /* MPLS  */
  YYSYMBOL_PPPOED = 73,                    /* PPPOED  */
  YYSYMBOL_PPPOES = 74,                    /* PPPOES  */
  YYSYMBOL_ISO = 75,                       /* ISO  */
  YYSYMBOL_ESIS = 76,                      /* ESIS  */
  YYSYMBOL_CLNP = 77,                      /* CLNP  */
  YYSYMBOL_ISIS = 78,                      /* ISIS  */
  YYSYMBOL_L1 = 79,                        /* L1  */
  YYSYMBOL_L2 = 80,                        /* L2  */
  YYSYMBOL_IIH = 81,                       /* IIH  */
  YYSYMBOL_LSP = 82,                       /* LSP  */
  YYSYMBOL_SNP = 83,                       /* SNP  */
  YYSYMBOL_CSNP = 84,                      /* CSNP  */
  YYSYMBOL_PSNP = 85,                      /* PSNP  */
  YYSYMBOL_STP = 86,                       /* STP  */
  YYSYMBOL_IPX = 87,                       /* IPX  */
  YYSYMBOL_NETBEUI = 88,                   /* NETBEUI  */
  YYSYMBOL_LANE = 89,                      /* LANE  */
  YYSYMBOL_LLC = 90,                       /* LLC  */
  YYSYMBOL_METAC = 91,                     /* METAC  */
  YYSYMBOL_BCC = 92,                       /* BCC  */
  YYSYMBOL_SC = 93,                        /* SC  */
  YYSYMBOL_ILMIC = 94,                     /* ILMIC  */
  YYSYMBOL_OAMF4EC = 95,                   /* OAMF4EC  */
  YYSYMBOL_OAMF4SC = 96,                   /* OAMF4SC  */
  YYSYMBOL_OAM = 97,                       /* OAM  */
  YYSYMBOL_OAMF4 = 98,                     /* OAMF4  */
  YYSYMBOL_CONNECTMSG = 99,                /* CONNECTMSG  */
  YYSYMBOL_METACONNECT = 100,              /* METACONNECT  */
  YYSYMBOL_VPI = 101,                      /* VPI  */
  YYSYMBOL_VCI = 102,                      /* VCI  */
  YYSYMBOL_RADIO = 103,                    /* RADIO  */
  YYSYMBOL_FISU = 104,                     /* FISU  */
  YYSYMBOL_LSSU = 105,                     /* LSSU  */
  YYSYMBOL_MSU = 106,                      /* MSU  */
  YYSYMBOL_SIO = 107,                      /* SIO  */
  YYSYMBOL_OPC = 108,                      /* OPC  */
  YYSYMBOL_DPC = 109,                      /* DPC  */
  YYSYMBOL_SLS = 110,                      /* SLS  */
  YYSYMBOL_OR = 111,                       /* OR  */
  YYSYMBOL_AND = 112,                      /* AND  */
  YYSYMBOL_113_ = 113,                     /* '!'  */
  YYSYMBOL_114_ = 114,                     /* '|'  */
  YYSYMBOL_115_ = 115,                     /* '&'  */
  YYSYMBOL_116_ = 116,                     /* '+'  */
  YYSYMBOL_117_ = 117,                     /* '-'  */
  YYSYMBOL_118_ = 118,                     /* '*'  */
  YYSYMBOL_119_ = 119,                     /* '/'  */
  YYSYMBOL_UMINUS = 120,                   /* UMINUS  */
  YYSYMBOL_121_ = 121,                     /* ')'  */
  YYSYMBOL_122_ = 122,                     /* '('  */
  YYSYMBOL_123_ = 123,                     /* '>'  */
  YYSYMBOL_124_ = 124,                     /* '='  */
  YYSYMBOL_125_ = 125,                     /* '<'  */
  YYSYMBOL_126_ = 126,                     /* '['  */
  YYSYMBOL_127_ = 127,                     /* ']'  */
  YYSYMBOL_128_ = 128,                     /* ':'  */
  YYSYMBOL_YYACCEPT = 129,                 /* $accept  */
  YYSYMBOL_prog = 130,                     /* prog  */
  YYSYMBOL_null = 131,                     /* null  */
  YYSYMBOL_expr = 132,                     /* expr  */
  YYSYMBOL_and = 133,                      /* and  */
  YYSYMBOL_or = 134,                       /* or  */
  YYSYMBOL_id = 135,                       /* id  */
  YYSYMBOL_nid = 136,                      /* nid  */
  YYSYMBOL_not = 137,                      /* not  */
  YYSYMBOL_paren = 138,                    /* paren  */
  YYSYMBOL_pid = 139,                      /* pid  */
  YYSYMBOL_qid = 140,                      /* qid  */
  YYSYMBOL_term = 141,                     /* term  */
  YYSYMBOL_head = 142,                     /* head  */
  YYSYMBOL_rterm = 143,                    /* rterm  */
  YYSYMBOL_pqual = 144,                    /* pqual  */
  YYSYMBOL_dqual = 145,                    /* dqual  */
  YYSYMBOL_aqual = 146,                    /* aqual  */
  YYSYMBOL_ndaqual = 147,                  /* ndaqual  */
  YYSYMBOL_pname = 148,                    /* pname  */
  YYSYMBOL_other = 149,                    /* other  */
  YYSYMBOL_pfvar = 150,                    /* pfvar  */
  YYSYMBOL_p80211 = 151,                   /* p80211  */
  YYSYMBOL_type = 152,                     /* type  */
  YYSYMBOL_subtype = 153,                  /* subtype  */
  YYSYMBOL_type_subtype = 154,             /* type_subtype  */
  YYSYMBOL_dir = 155,                      /* dir  */
  YYSYMBOL_reason = 156,                   /* reason  */
  YYSYMBOL_action = 157,                   /* action  */
  YYSYMBOL_relop = 158,                    /* relop  */
  YYSYMBOL_irelop = 159,                   /* irelop  */
  YYSYMBOL_arth = 160,                     /* arth  */
  YYSYMBOL_narth = 161,                    /* narth  */
  YYSYMBOL_byteop = 162,                   /* byteop  */
  YYSYMBOL_pnum = 163,                     /* pnum  */
  YYSYMBOL_atmtype = 164,                  /* atmtype  */
  YYSYMBOL_atmmultitype = 165,             /* atmmultitype  */
  YYSYMBOL_atmfield = 166,                 /* atmfield  */
  YYSYMBOL_atmvalue = 167,                 /* atmvalue  */
  YYSYMBOL_atmfieldvalue = 168,            /* atmfieldvalue  */
  YYSYMBOL_atmlistvalue = 169,             /* atmlistvalue  */
  YYSYMBOL_mtp2type = 170,                 /* mtp2type  */
  YYSYMBOL_mtp3field = 171,                /* mtp3field  */
  YYSYMBOL_mtp3value = 172,                /* mtp3value  */
  YYSYMBOL_mtp3fieldvalue = 173,           /* mtp3fieldvalue  */
  YYSYMBOL_mtp3listvalue = 174             /* mtp3listvalue  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   700

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  129
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  205
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  277

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   368


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   113,     2,     2,     2,     2,   115,     2,
     122,   121,   118,   116,     2,   117,     2,   119,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   128,     2,
     125,   124,   123,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   126,     2,   127,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   114,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   120
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   315,   315,   319,   321,   323,   324,   325,   326,   327,
     329,   331,   333,   334,   336,   338,   339,   341,   343,   356,
     365,   374,   383,   392,   394,   396,   398,   399,   400,   402,
     404,   406,   407,   409,   410,   411,   412,   413,   414,   416,
     417,   418,   419,   421,   423,   424,   425,   426,   427,   428,
     431,   432,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   449,   450,   451,   452,   455,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   506,   507,   508,
     509,   510,   511,   514,   515,   516,   517,   518,   519,   522,
     527,   530,   534,   537,   538,   544,   545,   565,   581,   582,
     595,   596,   599,   602,   603,   604,   606,   607,   608,   610,
     611,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   627,   628,   629,   630,   631,   633,
     634,   636,   637,   638,   639,   640,   641,   642,   643,   645,
     646,   647,   648,   651,   652,   654,   655,   656,   657,   659,
     666,   667,   670,   671,   672,   675,   676,   677,   678,   680,
     681,   682,   683,   685,   694,   695
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "DST", "SRC", "HOST",
  "GATEWAY", "NET", "NETMASK", "PORT", "PORTRANGE", "LESS", "GREATER",
  "PROTO", "PROTOCHAIN", "CBYTE", "ARP", "RARP", "IP", "SCTP", "TCP",
  "UDP", "ICMP", "IGMP", "IGRP", "PIM", "VRRP", "CARP", "ATALK", "AARP",
  "DECNET", "LAT", "SCA", "MOPRC", "MOPDL", "TK_BROADCAST", "TK_MULTICAST",
  "NUM", "INBOUND", "OUTBOUND", "PF_IFNAME", "PF_RSET", "PF_RNR",
  "PF_SRNR", "PF_REASON", "PF_ACTION", "TYPE", "SUBTYPE", "DIR", "ADDR1",
  "ADDR2", "ADDR3", "ADDR4", "RA", "TA", "LINK", "GEQ", "LEQ", "NEQ", "ID",
  "EID", "HID", "HID6", "AID", "LSH", "RSH", "LEN", "IPV6", "ICMPV6", "AH",
  "ESP", "VLAN", "MPLS", "PPPOED", "PPPOES", "ISO", "ESIS", "CLNP", "ISIS",
  "L1", "L2", "IIH", "LSP", "SNP", "CSNP", "PSNP", "STP", "IPX", "NETBEUI",
  "LANE", "LLC", "METAC", "BCC", "SC", "ILMIC", "OAMF4EC", "OAMF4SC",
  "OAM", "OAMF4", "CONNECTMSG", "METACONNECT", "VPI", "VCI", "RADIO",
  "FISU", "LSSU", "MSU", "SIO", "OPC", "DPC", "SLS", "OR", "AND", "'!'",
  "'|'", "'&'", "'+'", "'-'", "'*'", "'/'", "UMINUS", "')'", "'('", "'>'",
  "'='", "'<'", "'['", "']'", "':'", "$accept", "prog", "null", "expr",
  "and", "or", "id", "nid", "not", "paren", "pid", "qid", "term", "head",
  "rterm", "pqual", "dqual", "aqual", "ndaqual", "pname", "other", "pfvar",
  "p80211", "type", "subtype", "type_subtype", "dir", "reason", "action",
  "relop", "irelop", "arth", "narth", "byteop", "pnum", "atmtype",
  "atmmultitype", "atmfield", "atmvalue", "atmfieldvalue", "atmlistvalue",
  "mtp2type", "mtp3field", "mtp3value", "mtp3fieldvalue", "mtp3listvalue", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-193)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-42)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -193,    25,   218,  -193,    -6,    15,    32,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,    21,
      37,    74,    76,   -22,    59,  -193,  -193,  -193,  -193,  -193,
    -193,   -20,   -20,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
    -193,  -193,   541,  -193,   -55,   434,   434,  -193,   -15,  -193,
     646,    11,  -193,  -193,   523,  -193,  -193,  -193,  -193,    48,
    -193,    52,  -193,  -193,   -95,  -193,  -193,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,   -20,  -193,  -193,   541,    -1,  -193,
    -193,  -193,   326,   326,  -193,   -53,    26,    28,  -193,  -193,
      -3,    17,  -193,  -193,  -193,   -15,   -15,  -193,   -39,   -34,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,   -21,
      94,   -16,  -193,  -193,  -193,  -193,  -193,  -193,   147,  -193,
    -193,  -193,   541,  -193,  -193,  -193,   541,   541,   541,   541,
     541,   541,   541,   541,  -193,  -193,  -193,   541,   541,  -193,
     118,   125,   126,  -193,  -193,  -193,   127,   130,   149,  -193,
    -193,  -193,  -193,  -193,  -193,  -193,   150,    28,    96,  -193,
     326,   326,  -193,     3,  -193,  -193,  -193,  -193,  -193,   128,
     151,   153,  -193,  -193,    70,   -55,    28,   188,   189,   191,
     192,  -193,  -193,   154,  -193,  -193,  -193,  -193,  -193,  -193,
     -52,    66,    66,   152,    62,    40,    40,  -193,  -193,    96,
      96,  -193,   -40,  -193,  -193,  -193,    27,  -193,  -193,  -193,
     -51,  -193,  -193,  -193,  -193,   -15,   -15,  -193,  -193,  -193,
    -193,   -10,  -193,   159,  -193,   118,  -193,   127,  -193,  -193,
    -193,  -193,  -193,    73,  -193,  -193,  -193
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,    51,     1,     0,     0,     0,    71,    72,    70,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    88,    87,   169,   113,   114,     0,
       0,     0,     0,     0,     0,    69,   163,    89,    90,    91,
      92,   116,   118,   119,   120,    93,    94,   103,    95,    96,
      97,    98,    99,   100,   102,   101,   104,   105,   106,   171,
     172,   173,   174,   177,   178,   175,   176,   179,   180,   181,
     182,   183,   184,   107,   192,   193,   194,   195,   196,   197,
     198,    24,     0,    25,     2,    51,    51,     5,     0,    31,
       0,    50,    44,   121,     0,   150,   149,    45,    46,     0,
      48,     0,   110,   111,     0,   123,   124,   125,   126,   140,
     141,   127,   142,   128,     0,   115,   117,     0,     0,   161,
      11,    10,    51,    51,    32,     0,   150,   149,    15,    21,
      18,    20,    22,    39,    12,     0,     0,    13,    53,    52,
      64,    68,    65,    66,    67,    36,    37,   108,   109,     0,
       0,     0,    58,    59,    60,    61,    62,    63,    34,    35,
      38,   122,     0,   144,   146,   148,     0,     0,     0,     0,
       0,     0,     0,     0,   143,   145,   147,     0,     0,   189,
       0,     0,     0,    47,   185,   203,     0,     0,     0,    49,
     199,   165,   164,   167,   168,   166,     0,     0,     0,     7,
      51,    51,     6,   149,     9,     8,    40,   162,   170,     0,
       0,     0,    23,    26,    30,     0,    29,     0,     0,     0,
       0,   133,   134,   130,   137,   131,   138,   139,   132,    33,
       0,   159,   160,   158,   157,   153,   154,   155,   156,    42,
      43,   190,     0,   186,   187,   204,     0,   200,   201,   112,
     149,    17,    16,    19,    14,     0,     0,    55,    57,    54,
      56,     0,   151,     0,   188,     0,   202,     0,    27,    28,
     135,   136,   129,     0,   191,   205,   152
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -193,  -193,  -193,   195,   -13,  -192,   -87,  -127,     6,    -2,
    -193,  -193,   -81,  -193,  -193,  -193,  -193,    45,  -193,     8,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,   -75,
     -67,   -27,   -84,  -193,   -35,  -193,  -193,  -193,  -193,  -162,
    -193,  -193,  -193,  -193,  -172,  -193
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,   125,   122,   123,   212,   134,   135,   117,
     214,   215,    87,    88,    89,    90,   158,   159,   160,   118,
      92,    93,   161,   223,   272,   225,   228,   111,   113,   177,
     178,    94,    95,   196,    96,    97,    98,    99,   183,   184,
     242,   100,   101,   189,   190,   246
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      86,   133,   126,   -13,   124,   209,   115,   116,    85,   213,
      91,   -41,   166,   167,   245,   109,   221,    26,   241,   191,
     192,   226,    26,   256,   181,     3,   187,   270,   193,   194,
     195,   102,   182,   126,   188,   199,   204,   110,   222,   114,
     114,   202,   205,   227,   128,   129,   130,   131,   132,   271,
     265,   127,   103,   137,   267,   119,   120,   121,   120,   121,
     -29,   -29,   168,   169,   170,   171,   172,   173,   206,   104,
     208,   120,   217,   218,   213,   262,   263,   219,   220,   197,
     105,   264,   127,    86,    86,   179,   136,   203,   203,   185,
     198,    85,    85,    91,    91,   275,   106,   180,    81,   186,
     137,   216,    83,   274,   163,   164,   165,    83,   163,   164,
     165,   107,   114,   108,   -13,   -13,   210,   126,   112,   124,
     201,   201,   -41,   -41,   -13,   162,   166,   167,   200,   200,
      91,    91,   -41,   136,   114,   230,   211,   162,   120,   231,
     232,   233,   234,   235,   236,   237,   238,   207,   266,   208,
     239,   240,   140,   224,   142,   179,   143,   144,   172,   173,
     166,   167,   243,   244,   185,   203,   250,   247,   268,   269,
      83,   174,   175,   176,    83,   174,   175,   176,   170,   171,
     172,   173,   170,   171,   172,   173,   248,   249,   252,   251,
     253,   254,   257,   258,   259,   260,   273,    84,   201,    86,
     276,   261,   255,   229,     0,     0,   200,   200,    91,    91,
     168,   169,   170,   171,   172,   173,   166,   167,    -3,     0,
     137,   137,     0,     0,     0,     0,     0,     0,     0,     4,
       5,     0,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   136,   136,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,     0,     0,   169,   170,   171,
     172,   173,     0,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,     0,
       0,    81,     0,     0,     0,    82,     0,     4,     5,     0,
      83,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    35,     0,     0,     0,   128,   129,   130,   131,   132,
       0,     0,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,     0,     0,    81,
       0,     0,     0,    82,     0,     4,     5,     0,    83,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
       0,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,     0,     0,    81,     0,     0,
       0,    82,     0,     0,     0,     0,    83,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,     0,    26,   163,
     164,   165,     0,     0,     0,     0,     0,   166,   167,     0,
       0,     0,     0,     0,     0,     0,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,    37,    38,
      39,    40,     0,     0,     0,     0,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
       0,     0,     0,     0,     0,     0,     0,   168,   169,   170,
     171,   172,   173,     0,    73,     0,   174,   175,   176,   138,
     139,   140,   141,   142,     0,   143,   144,     0,    82,   145,
     146,     0,     0,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   147,   148,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   149,   150,   151,   152,   153,   154,   155,   156,
     157
};

static const yytype_int16 yycheck[] =
{
       2,    88,    86,     0,    85,     8,    41,    42,     2,   136,
       2,     0,    64,    65,   186,    37,    37,    37,   180,   114,
     115,    37,    37,   215,    99,     0,   101,    37,   123,   124,
     125,    37,    99,   117,   101,   122,   123,    59,    59,    41,
      42,   122,   123,    59,    59,    60,    61,    62,    63,    59,
     242,    86,    37,    88,   246,    82,   111,   112,   111,   112,
     111,   112,   114,   115,   116,   117,   118,   119,   121,    37,
     121,   111,   111,   112,   201,   127,   128,   111,   112,   114,
      59,   121,   117,    85,    86,    37,    88,   122,   123,    37,
     117,    85,    86,    85,    86,   267,    59,    99,   113,   101,
     135,   136,   122,   265,    56,    57,    58,   122,    56,    57,
      58,    37,   114,    37,   111,   112,   119,   201,    59,   200,
     122,   123,   111,   112,   121,   126,    64,    65,   122,   123,
     122,   123,   121,   135,   136,   162,   119,   126,   111,   166,
     167,   168,   169,   170,   171,   172,   173,   121,   121,   121,
     177,   178,     5,    59,     7,    37,     9,    10,   118,   119,
      64,    65,    37,    37,    37,   200,   201,    37,   255,   256,
     122,   123,   124,   125,   122,   123,   124,   125,   116,   117,
     118,   119,   116,   117,   118,   119,    37,    37,    37,    61,
      37,   121,     4,     4,     3,     3,    37,     2,   200,   201,
     127,    47,   215,   158,    -1,    -1,   200,   201,   200,   201,
     114,   115,   116,   117,   118,   119,    64,    65,     0,    -1,
     255,   256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,   255,   256,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    -1,   115,   116,   117,
     118,   119,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    -1,
      -1,   113,    -1,    -1,    -1,   117,    -1,    11,    12,    -1,
     122,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    59,    60,    61,    62,    63,
      -1,    -1,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,    -1,    -1,   113,
      -1,    -1,    -1,   117,    -1,    11,    12,    -1,   122,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,    -1,    -1,   113,    -1,    -1,
      -1,   117,    -1,    -1,    -1,    -1,   122,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    37,    56,
      57,    58,    -1,    -1,    -1,    -1,    -1,    64,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,
      69,    70,    -1,    -1,    -1,    -1,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,   116,
     117,   118,   119,    -1,   103,    -1,   123,   124,   125,     3,
       4,     5,     6,     7,    -1,     9,    10,    -1,   117,    13,
      14,    -1,    -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   130,   131,     0,    11,    12,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    55,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   113,   117,   122,   132,   137,   138,   141,   142,   143,
     144,   148,   149,   150,   160,   161,   163,   164,   165,   166,
     170,   171,    37,    37,    37,    59,    59,    37,    37,    37,
      59,   156,    59,   157,   138,   163,   163,   138,   148,   160,
     111,   112,   133,   134,   141,   132,   161,   163,    59,    60,
      61,    62,    63,   135,   136,   137,   138,   163,     3,     4,
       5,     6,     7,     9,    10,    13,    14,    35,    36,    46,
      47,    48,    49,    50,    51,    52,    53,    54,   145,   146,
     147,   151,   126,    56,    57,    58,    64,    65,   114,   115,
     116,   117,   118,   119,   123,   124,   125,   158,   159,    37,
     138,   158,   159,   167,   168,    37,   138,   158,   159,   172,
     173,   114,   115,   123,   124,   125,   162,   163,   160,   135,
     137,   138,   141,   163,   135,   141,   121,   121,   121,     8,
     119,   119,   135,   136,   139,   140,   163,   111,   112,   111,
     112,    37,    59,   152,    59,   154,    37,    59,   155,   146,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   168,   169,    37,    37,   173,   174,    37,    37,    37,
     163,    61,    37,    37,   121,   133,   134,     4,     4,     3,
       3,    47,   127,   128,   121,   134,   121,   134,   135,   135,
      37,    59,   153,    37,   168,   173,   127
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   129,   130,   130,   131,   132,   132,   132,   132,   132,
     133,   134,   135,   135,   135,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   137,   138,   139,   139,   139,   140,
     140,   141,   141,   142,   142,   142,   142,   142,   142,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     144,   144,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   146,   146,   146,   146,   147,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   150,   150,   150,   150,   150,   150,   151,
     151,   151,   151,   152,   152,   153,   153,   154,   155,   155,
     156,   156,   157,   158,   158,   158,   159,   159,   159,   160,
     160,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   162,   162,   162,   162,   162,   163,
     163,   164,   164,   164,   164,   164,   164,   164,   164,   165,
     165,   165,   165,   166,   166,   167,   167,   167,   167,   168,
     169,   169,   170,   170,   170,   171,   171,   171,   171,   172,
     172,   172,   172,   173,   174,   174
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     0,     1,     3,     3,     3,     3,
       1,     1,     1,     1,     3,     1,     3,     3,     1,     3,
       1,     1,     1,     2,     1,     1,     1,     3,     3,     1,
       1,     1,     2,     3,     2,     2,     2,     2,     2,     2,
       3,     1,     3,     3,     1,     1,     1,     2,     1,     2,
       1,     0,     1,     1,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     4,     1,     1,     2,     1,     2,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     2,     4,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     6,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     3,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* prog: null expr  */
#line 316 "grammar.y"
{
	finish_parse((yyvsp[0].blk).b);
}
#line 2075 "y.tab.c"
    break;

  case 4: /* null: %empty  */
#line 321 "grammar.y"
                                { (yyval.blk).q = qerr; }
#line 2081 "y.tab.c"
    break;

  case 6: /* expr: expr and term  */
#line 324 "grammar.y"
                                { gen_and((yyvsp[-2].blk).b, (yyvsp[0].blk).b); (yyval.blk) = (yyvsp[0].blk); }
#line 2087 "y.tab.c"
    break;

  case 7: /* expr: expr and id  */
#line 325 "grammar.y"
                                { gen_and((yyvsp[-2].blk).b, (yyvsp[0].blk).b); (yyval.blk) = (yyvsp[0].blk); }
#line 2093 "y.tab.c"
    break;

  case 8: /* expr: expr or term  */
#line 326 "grammar.y"
                                { gen_or((yyvsp[-2].blk).b, (yyvsp[0].blk).b); (yyval.blk) = (yyvsp[0].blk); }
#line 2099 "y.tab.c"
    break;

  case 9: /* expr: expr or id  */
#line 327 "grammar.y"
                                { gen_or((yyvsp[-2].blk).b, (yyvsp[0].blk).b); (yyval.blk) = (yyvsp[0].blk); }
#line 2105 "y.tab.c"
    break;

  case 10: /* and: AND  */
#line 329 "grammar.y"
                                { (yyval.blk) = (yyvsp[-1].blk); }
#line 2111 "y.tab.c"
    break;

  case 11: /* or: OR  */
#line 331 "grammar.y"
                                { (yyval.blk) = (yyvsp[-1].blk); }
#line 2117 "y.tab.c"
    break;

  case 13: /* id: pnum  */
#line 334 "grammar.y"
                                { (yyval.blk).b = gen_ncode(NULL, (bpf_u_int32)(yyvsp[0].i),
						   (yyval.blk).q = (yyvsp[-1].blk).q); }
#line 2124 "y.tab.c"
    break;

  case 14: /* id: paren pid ')'  */
#line 336 "grammar.y"
                                { (yyval.blk) = (yyvsp[-1].blk); }
#line 2130 "y.tab.c"
    break;

  case 15: /* nid: ID  */
#line 338 "grammar.y"
                                { (yyval.blk).b = gen_scode((yyvsp[0].s), (yyval.blk).q = (yyvsp[-1].blk).q); }
#line 2136 "y.tab.c"
    break;

  case 16: /* nid: HID '/' NUM  */
#line 339 "grammar.y"
                                { (yyval.blk).b = gen_mcode((yyvsp[-2].s), NULL, (yyvsp[0].i),
				    (yyval.blk).q = (yyvsp[-3].blk).q); }
#line 2143 "y.tab.c"
    break;

  case 17: /* nid: HID NETMASK HID  */
#line 341 "grammar.y"
                                { (yyval.blk).b = gen_mcode((yyvsp[-2].s), (yyvsp[0].s), 0,
				    (yyval.blk).q = (yyvsp[-3].blk).q); }
#line 2150 "y.tab.c"
    break;

  case 18: /* nid: HID  */
#line 343 "grammar.y"
                                {
				  /* Decide how to parse HID based on proto */
				  (yyval.blk).q = (yyvsp[-1].blk).q;
				  if ((yyval.blk).q.addr == Q_PORT)
				  	bpf_error("'port' modifier applied to ip host");
				  else if ((yyval.blk).q.addr == Q_PORTRANGE)
				  	bpf_error("'portrange' modifier applied to ip host");
				  else if ((yyval.blk).q.addr == Q_PROTO)
				  	bpf_error("'proto' modifier applied to ip host");
				  else if ((yyval.blk).q.addr == Q_PROTOCHAIN)
				  	bpf_error("'protochain' modifier applied to ip host");
				  (yyval.blk).b = gen_ncode((yyvsp[0].s), 0, (yyval.blk).q);
				}
#line 2168 "y.tab.c"
    break;

  case 19: /* nid: HID6 '/' NUM  */
#line 356 "grammar.y"
                                {
#ifdef INET6
				  (yyval.blk).b = gen_mcode6((yyvsp[-2].s), NULL, (yyvsp[0].i),
				    (yyval.blk).q = (yyvsp[-3].blk).q);
#else
				  bpf_error("'ip6addr/prefixlen' not supported "
					"in this configuration");
#endif /*INET6*/
				}
#line 2182 "y.tab.c"
    break;

  case 20: /* nid: HID6  */
#line 365 "grammar.y"
                                {
#ifdef INET6
				  (yyval.blk).b = gen_mcode6((yyvsp[0].s), 0, 128,
				    (yyval.blk).q = (yyvsp[-1].blk).q);
#else
				  bpf_error("'ip6addr' not supported "
					"in this configuration");
#endif /*INET6*/
				}
#line 2196 "y.tab.c"
    break;

  case 21: /* nid: EID  */
#line 374 "grammar.y"
                                { 
				  (yyval.blk).b = gen_ecode((yyvsp[0].e), (yyval.blk).q = (yyvsp[-1].blk).q);
				  /*
				   * $1 was allocated by "pcap_ether_aton()",
				   * so we must free it now that we're done
				   * with it.
				   */
				  free((yyvsp[0].e));
				}
#line 2210 "y.tab.c"
    break;

  case 22: /* nid: AID  */
#line 383 "grammar.y"
                                {
				  (yyval.blk).b = gen_acode((yyvsp[0].e), (yyval.blk).q = (yyvsp[-1].blk).q);
				  /*
				   * $1 was allocated by "pcap_ether_aton()",
				   * so we must free it now that we're done
				   * with it.
				   */
				  free((yyvsp[0].e));
				}
#line 2224 "y.tab.c"
    break;

  case 23: /* nid: not id  */
#line 392 "grammar.y"
                                { gen_not((yyvsp[0].blk).b); (yyval.blk) = (yyvsp[0].blk); }
#line 2230 "y.tab.c"
    break;

  case 24: /* not: '!'  */
#line 394 "grammar.y"
                                { (yyval.blk) = (yyvsp[-1].blk); }
#line 2236 "y.tab.c"
    break;

  case 25: /* paren: '('  */
#line 396 "grammar.y"
                                { (yyval.blk) = (yyvsp[-1].blk); }
#line 2242 "y.tab.c"
    break;

  case 27: /* pid: qid and id  */
#line 399 "grammar.y"
                                { gen_and((yyvsp[-2].blk).b, (yyvsp[0].blk).b); (yyval.blk) = (yyvsp[0].blk); }
#line 2248 "y.tab.c"
    break;

  case 28: /* pid: qid or id  */
#line 400 "grammar.y"
                                { gen_or((yyvsp[-2].blk).b, (yyvsp[0].blk).b); (yyval.blk) = (yyvsp[0].blk); }
#line 2254 "y.tab.c"
    break;

  case 29: /* qid: pnum  */
#line 402 "grammar.y"
                                { (yyval.blk).b = gen_ncode(NULL, (bpf_u_int32)(yyvsp[0].i),
						   (yyval.blk).q = (yyvsp[-1].blk).q); }
#line 2261 "y.tab.c"
    break;

  case 32: /* term: not term  */
#line 407 "grammar.y"
                                { gen_not((yyvsp[0].blk).b); (yyval.blk) = (yyvsp[0].blk); }
#line 2267 "y.tab.c"
    break;

  case 33: /* head: pqual dqual aqual  */
#line 409 "grammar.y"
                                { QSET((yyval.blk).q, (yyvsp[-2].i), (yyvsp[-1].i), (yyvsp[0].i)); }
#line 2273 "y.tab.c"
    break;

  case 34: /* head: pqual dqual  */
#line 410 "grammar.y"
                                { QSET((yyval.blk).q, (yyvsp[-1].i), (yyvsp[0].i), Q_DEFAULT); }
#line 2279 "y.tab.c"
    break;

  case 35: /* head: pqual aqual  */
#line 411 "grammar.y"
                                { QSET((yyval.blk).q, (yyvsp[-1].i), Q_DEFAULT, (yyvsp[0].i)); }
#line 2285 "y.tab.c"
    break;

  case 36: /* head: pqual PROTO  */
#line 412 "grammar.y"
                                { QSET((yyval.blk).q, (yyvsp[-1].i), Q_DEFAULT, Q_PROTO); }
#line 2291 "y.tab.c"
    break;

  case 37: /* head: pqual PROTOCHAIN  */
#line 413 "grammar.y"
                                { QSET((yyval.blk).q, (yyvsp[-1].i), Q_DEFAULT, Q_PROTOCHAIN); }
#line 2297 "y.tab.c"
    break;

  case 38: /* head: pqual ndaqual  */
#line 414 "grammar.y"
                                { QSET((yyval.blk).q, (yyvsp[-1].i), Q_DEFAULT, (yyvsp[0].i)); }
#line 2303 "y.tab.c"
    break;

  case 39: /* rterm: head id  */
#line 416 "grammar.y"
                                { (yyval.blk) = (yyvsp[0].blk); }
#line 2309 "y.tab.c"
    break;

  case 40: /* rterm: paren expr ')'  */
#line 417 "grammar.y"
                                { (yyval.blk).b = (yyvsp[-1].blk).b; (yyval.blk).q = (yyvsp[-2].blk).q; }
#line 2315 "y.tab.c"
    break;

  case 41: /* rterm: pname  */
#line 418 "grammar.y"
                                { (yyval.blk).b = gen_proto_abbrev((yyvsp[0].i)); (yyval.blk).q = qerr; }
#line 2321 "y.tab.c"
    break;

  case 42: /* rterm: arth relop arth  */
#line 419 "grammar.y"
                                { (yyval.blk).b = gen_relation((yyvsp[-1].i), (yyvsp[-2].a), (yyvsp[0].a), 0);
				  (yyval.blk).q = qerr; }
#line 2328 "y.tab.c"
    break;

  case 43: /* rterm: arth irelop arth  */
#line 421 "grammar.y"
                                { (yyval.blk).b = gen_relation((yyvsp[-1].i), (yyvsp[-2].a), (yyvsp[0].a), 1);
				  (yyval.blk).q = qerr; }
#line 2335 "y.tab.c"
    break;

  case 44: /* rterm: other  */
#line 423 "grammar.y"
                                { (yyval.blk).b = (yyvsp[0].rblk); (yyval.blk).q = qerr; }
#line 2341 "y.tab.c"
    break;

  case 45: /* rterm: atmtype  */
#line 424 "grammar.y"
                                { (yyval.blk).b = gen_atmtype_abbrev((yyvsp[0].i)); (yyval.blk).q = qerr; }
#line 2347 "y.tab.c"
    break;

  case 46: /* rterm: atmmultitype  */
#line 425 "grammar.y"
                                { (yyval.blk).b = gen_atmmulti_abbrev((yyvsp[0].i)); (yyval.blk).q = qerr; }
#line 2353 "y.tab.c"
    break;

  case 47: /* rterm: atmfield atmvalue  */
#line 426 "grammar.y"
                                { (yyval.blk).b = (yyvsp[0].blk).b; (yyval.blk).q = qerr; }
#line 2359 "y.tab.c"
    break;

  case 48: /* rterm: mtp2type  */
#line 427 "grammar.y"
                                { (yyval.blk).b = gen_mtp2type_abbrev((yyvsp[0].i)); (yyval.blk).q = qerr; }
#line 2365 "y.tab.c"
    break;

  case 49: /* rterm: mtp3field mtp3value  */
#line 428 "grammar.y"
                                { (yyval.blk).b = (yyvsp[0].blk).b; (yyval.blk).q = qerr; }
#line 2371 "y.tab.c"
    break;

  case 51: /* pqual: %empty  */
#line 432 "grammar.y"
                                { (yyval.i) = Q_DEFAULT; }
#line 2377 "y.tab.c"
    break;

  case 52: /* dqual: SRC  */
#line 435 "grammar.y"
                                { (yyval.i) = Q_SRC; }
#line 2383 "y.tab.c"
    break;

  case 53: /* dqual: DST  */
#line 436 "grammar.y"
                                { (yyval.i) = Q_DST; }
#line 2389 "y.tab.c"
    break;

  case 54: /* dqual: SRC OR DST  */
#line 437 "grammar.y"
                                { (yyval.i) = Q_OR; }
#line 2395 "y.tab.c"
    break;

  case 55: /* dqual: DST OR SRC  */
#line 438 "grammar.y"
                                { (yyval.i) = Q_OR; }
#line 2401 "y.tab.c"
    break;

  case 56: /* dqual: SRC AND DST  */
#line 439 "grammar.y"
                                { (yyval.i) = Q_AND; }
#line 2407 "y.tab.c"
    break;

  case 57: /* dqual: DST AND SRC  */
#line 440 "grammar.y"
                                { (yyval.i) = Q_AND; }
#line 2413 "y.tab.c"
    break;

  case 58: /* dqual: ADDR1  */
#line 441 "grammar.y"
                                { (yyval.i) = Q_ADDR1; }
#line 2419 "y.tab.c"
    break;

  case 59: /* dqual: ADDR2  */
#line 442 "grammar.y"
                                { (yyval.i) = Q_ADDR2; }
#line 2425 "y.tab.c"
    break;

  case 60: /* dqual: ADDR3  */
#line 443 "grammar.y"
                                { (yyval.i) = Q_ADDR3; }
#line 2431 "y.tab.c"
    break;

  case 61: /* dqual: ADDR4  */
#line 444 "grammar.y"
                                { (yyval.i) = Q_ADDR4; }
#line 2437 "y.tab.c"
    break;

  case 62: /* dqual: RA  */
#line 445 "grammar.y"
                                { (yyval.i) = Q_RA; }
#line 2443 "y.tab.c"
    break;

  case 63: /* dqual: TA  */
#line 446 "grammar.y"
                                { (yyval.i) = Q_TA; }
#line 2449 "y.tab.c"
    break;

  case 64: /* aqual: HOST  */
#line 449 "grammar.y"
                                { (yyval.i) = Q_HOST; }
#line 2455 "y.tab.c"
    break;

  case 65: /* aqual: NET  */
#line 450 "grammar.y"
                                { (yyval.i) = Q_NET; }
#line 2461 "y.tab.c"
    break;

  case 66: /* aqual: PORT  */
#line 451 "grammar.y"
                                { (yyval.i) = Q_PORT; }
#line 2467 "y.tab.c"
    break;

  case 67: /* aqual: PORTRANGE  */
#line 452 "grammar.y"
                                { (yyval.i) = Q_PORTRANGE; }
#line 2473 "y.tab.c"
    break;

  case 68: /* ndaqual: GATEWAY  */
#line 455 "grammar.y"
                                { (yyval.i) = Q_GATEWAY; }
#line 2479 "y.tab.c"
    break;

  case 69: /* pname: LINK  */
#line 457 "grammar.y"
                                { (yyval.i) = Q_LINK; }
#line 2485 "y.tab.c"
    break;

  case 70: /* pname: IP  */
#line 458 "grammar.y"
                                { (yyval.i) = Q_IP; }
#line 2491 "y.tab.c"
    break;

  case 71: /* pname: ARP  */
#line 459 "grammar.y"
                                { (yyval.i) = Q_ARP; }
#line 2497 "y.tab.c"
    break;

  case 72: /* pname: RARP  */
#line 460 "grammar.y"
                                { (yyval.i) = Q_RARP; }
#line 2503 "y.tab.c"
    break;

  case 73: /* pname: SCTP  */
#line 461 "grammar.y"
                                { (yyval.i) = Q_SCTP; }
#line 2509 "y.tab.c"
    break;

  case 74: /* pname: TCP  */
#line 462 "grammar.y"
                                { (yyval.i) = Q_TCP; }
#line 2515 "y.tab.c"
    break;

  case 75: /* pname: UDP  */
#line 463 "grammar.y"
                                { (yyval.i) = Q_UDP; }
#line 2521 "y.tab.c"
    break;

  case 76: /* pname: ICMP  */
#line 464 "grammar.y"
                                { (yyval.i) = Q_ICMP; }
#line 2527 "y.tab.c"
    break;

  case 77: /* pname: IGMP  */
#line 465 "grammar.y"
                                { (yyval.i) = Q_IGMP; }
#line 2533 "y.tab.c"
    break;

  case 78: /* pname: IGRP  */
#line 466 "grammar.y"
                                { (yyval.i) = Q_IGRP; }
#line 2539 "y.tab.c"
    break;

  case 79: /* pname: PIM  */
#line 467 "grammar.y"
                                { (yyval.i) = Q_PIM; }
#line 2545 "y.tab.c"
    break;

  case 80: /* pname: VRRP  */
#line 468 "grammar.y"
                                { (yyval.i) = Q_VRRP; }
#line 2551 "y.tab.c"
    break;

  case 81: /* pname: CARP  */
#line 469 "grammar.y"
                                { (yyval.i) = Q_CARP; }
#line 2557 "y.tab.c"
    break;

  case 82: /* pname: ATALK  */
#line 470 "grammar.y"
                                { (yyval.i) = Q_ATALK; }
#line 2563 "y.tab.c"
    break;

  case 83: /* pname: AARP  */
#line 471 "grammar.y"
                                { (yyval.i) = Q_AARP; }
#line 2569 "y.tab.c"
    break;

  case 84: /* pname: DECNET  */
#line 472 "grammar.y"
                                { (yyval.i) = Q_DECNET; }
#line 2575 "y.tab.c"
    break;

  case 85: /* pname: LAT  */
#line 473 "grammar.y"
                                { (yyval.i) = Q_LAT; }
#line 2581 "y.tab.c"
    break;

  case 86: /* pname: SCA  */
#line 474 "grammar.y"
                                { (yyval.i) = Q_SCA; }
#line 2587 "y.tab.c"
    break;

  case 87: /* pname: MOPDL  */
#line 475 "grammar.y"
                                { (yyval.i) = Q_MOPDL; }
#line 2593 "y.tab.c"
    break;

  case 88: /* pname: MOPRC  */
#line 476 "grammar.y"
                                { (yyval.i) = Q_MOPRC; }
#line 2599 "y.tab.c"
    break;

  case 89: /* pname: IPV6  */
#line 477 "grammar.y"
                                { (yyval.i) = Q_IPV6; }
#line 2605 "y.tab.c"
    break;

  case 90: /* pname: ICMPV6  */
#line 478 "grammar.y"
                                { (yyval.i) = Q_ICMPV6; }
#line 2611 "y.tab.c"
    break;

  case 91: /* pname: AH  */
#line 479 "grammar.y"
                                { (yyval.i) = Q_AH; }
#line 2617 "y.tab.c"
    break;

  case 92: /* pname: ESP  */
#line 480 "grammar.y"
                                { (yyval.i) = Q_ESP; }
#line 2623 "y.tab.c"
    break;

  case 93: /* pname: ISO  */
#line 481 "grammar.y"
                                { (yyval.i) = Q_ISO; }
#line 2629 "y.tab.c"
    break;

  case 94: /* pname: ESIS  */
#line 482 "grammar.y"
                                { (yyval.i) = Q_ESIS; }
#line 2635 "y.tab.c"
    break;

  case 95: /* pname: ISIS  */
#line 483 "grammar.y"
                                { (yyval.i) = Q_ISIS; }
#line 2641 "y.tab.c"
    break;

  case 96: /* pname: L1  */
#line 484 "grammar.y"
                                { (yyval.i) = Q_ISIS_L1; }
#line 2647 "y.tab.c"
    break;

  case 97: /* pname: L2  */
#line 485 "grammar.y"
                                { (yyval.i) = Q_ISIS_L2; }
#line 2653 "y.tab.c"
    break;

  case 98: /* pname: IIH  */
#line 486 "grammar.y"
                                { (yyval.i) = Q_ISIS_IIH; }
#line 2659 "y.tab.c"
    break;

  case 99: /* pname: LSP  */
#line 487 "grammar.y"
                                { (yyval.i) = Q_ISIS_LSP; }
#line 2665 "y.tab.c"
    break;

  case 100: /* pname: SNP  */
#line 488 "grammar.y"
                                { (yyval.i) = Q_ISIS_SNP; }
#line 2671 "y.tab.c"
    break;

  case 101: /* pname: PSNP  */
#line 489 "grammar.y"
                                { (yyval.i) = Q_ISIS_PSNP; }
#line 2677 "y.tab.c"
    break;

  case 102: /* pname: CSNP  */
#line 490 "grammar.y"
                                { (yyval.i) = Q_ISIS_CSNP; }
#line 2683 "y.tab.c"
    break;

  case 103: /* pname: CLNP  */
#line 491 "grammar.y"
                                { (yyval.i) = Q_CLNP; }
#line 2689 "y.tab.c"
    break;

  case 104: /* pname: STP  */
#line 492 "grammar.y"
                                { (yyval.i) = Q_STP; }
#line 2695 "y.tab.c"
    break;

  case 105: /* pname: IPX  */
#line 493 "grammar.y"
                                { (yyval.i) = Q_IPX; }
#line 2701 "y.tab.c"
    break;

  case 106: /* pname: NETBEUI  */
#line 494 "grammar.y"
                                { (yyval.i) = Q_NETBEUI; }
#line 2707 "y.tab.c"
    break;

  case 107: /* pname: RADIO  */
#line 495 "grammar.y"
                                { (yyval.i) = Q_RADIO; }
#line 2713 "y.tab.c"
    break;

  case 108: /* other: pqual TK_BROADCAST  */
#line 497 "grammar.y"
                                { (yyval.rblk) = gen_broadcast((yyvsp[-1].i)); }
#line 2719 "y.tab.c"
    break;

  case 109: /* other: pqual TK_MULTICAST  */
#line 498 "grammar.y"
                                { (yyval.rblk) = gen_multicast((yyvsp[-1].i)); }
#line 2725 "y.tab.c"
    break;

  case 110: /* other: LESS NUM  */
#line 499 "grammar.y"
                                { (yyval.rblk) = gen_less((yyvsp[0].i)); }
#line 2731 "y.tab.c"
    break;

  case 111: /* other: GREATER NUM  */
#line 500 "grammar.y"
                                { (yyval.rblk) = gen_greater((yyvsp[0].i)); }
#line 2737 "y.tab.c"
    break;

  case 112: /* other: CBYTE NUM byteop NUM  */
#line 501 "grammar.y"
                                { (yyval.rblk) = gen_byteop((yyvsp[-1].i), (yyvsp[-2].i), (yyvsp[0].i)); }
#line 2743 "y.tab.c"
    break;

  case 113: /* other: INBOUND  */
#line 502 "grammar.y"
                                { (yyval.rblk) = gen_inbound(0); }
#line 2749 "y.tab.c"
    break;

  case 114: /* other: OUTBOUND  */
#line 503 "grammar.y"
                                { (yyval.rblk) = gen_inbound(1); }
#line 2755 "y.tab.c"
    break;

  case 115: /* other: VLAN pnum  */
#line 504 "grammar.y"
                                { (yyval.rblk) = gen_vlan((yyvsp[0].i)); }
#line 2761 "y.tab.c"
    break;

  case 116: /* other: VLAN  */
#line 505 "grammar.y"
                                { (yyval.rblk) = gen_vlan(-1); }
#line 2767 "y.tab.c"
    break;

  case 117: /* other: MPLS pnum  */
#line 506 "grammar.y"
                                { (yyval.rblk) = gen_mpls((yyvsp[0].i)); }
#line 2773 "y.tab.c"
    break;

  case 118: /* other: MPLS  */
#line 507 "grammar.y"
                                { (yyval.rblk) = gen_mpls(-1); }
#line 2779 "y.tab.c"
    break;

  case 119: /* other: PPPOED  */
#line 508 "grammar.y"
                                { (yyval.rblk) = gen_pppoed(); }
#line 2785 "y.tab.c"
    break;

  case 120: /* other: PPPOES  */
#line 509 "grammar.y"
                                { (yyval.rblk) = gen_pppoes(); }
#line 2791 "y.tab.c"
    break;

  case 121: /* other: pfvar  */
#line 510 "grammar.y"
                                { (yyval.rblk) = (yyvsp[0].rblk); }
#line 2797 "y.tab.c"
    break;

  case 122: /* other: pqual p80211  */
#line 511 "grammar.y"
                                { (yyval.rblk) = (yyvsp[0].rblk); }
#line 2803 "y.tab.c"
    break;

  case 123: /* pfvar: PF_IFNAME ID  */
#line 514 "grammar.y"
                                { (yyval.rblk) = gen_pf_ifname((yyvsp[0].s)); }
#line 2809 "y.tab.c"
    break;

  case 124: /* pfvar: PF_RSET ID  */
#line 515 "grammar.y"
                                { (yyval.rblk) = gen_pf_ruleset((yyvsp[0].s)); }
#line 2815 "y.tab.c"
    break;

  case 125: /* pfvar: PF_RNR NUM  */
#line 516 "grammar.y"
                                { (yyval.rblk) = gen_pf_rnr((yyvsp[0].i)); }
#line 2821 "y.tab.c"
    break;

  case 126: /* pfvar: PF_SRNR NUM  */
#line 517 "grammar.y"
                                { (yyval.rblk) = gen_pf_srnr((yyvsp[0].i)); }
#line 2827 "y.tab.c"
    break;

  case 127: /* pfvar: PF_REASON reason  */
#line 518 "grammar.y"
                                { (yyval.rblk) = gen_pf_reason((yyvsp[0].i)); }
#line 2833 "y.tab.c"
    break;

  case 128: /* pfvar: PF_ACTION action  */
#line 519 "grammar.y"
                                { (yyval.rblk) = gen_pf_action((yyvsp[0].i)); }
#line 2839 "y.tab.c"
    break;

  case 129: /* p80211: TYPE type SUBTYPE subtype  */
#line 523 "grammar.y"
                                { (yyval.rblk) = gen_p80211_type((yyvsp[-2].i) | (yyvsp[0].i),
					IEEE80211_FC0_TYPE_MASK |
					IEEE80211_FC0_SUBTYPE_MASK);
				}
#line 2848 "y.tab.c"
    break;

  case 130: /* p80211: TYPE type  */
#line 527 "grammar.y"
                                { (yyval.rblk) = gen_p80211_type((yyvsp[0].i),
					IEEE80211_FC0_TYPE_MASK);
				}
#line 2856 "y.tab.c"
    break;

  case 131: /* p80211: SUBTYPE type_subtype  */
#line 530 "grammar.y"
                                { (yyval.rblk) = gen_p80211_type((yyvsp[0].i),
					IEEE80211_FC0_TYPE_MASK |
					IEEE80211_FC0_SUBTYPE_MASK);
				}
#line 2865 "y.tab.c"
    break;

  case 132: /* p80211: DIR dir  */
#line 534 "grammar.y"
                                { (yyval.rblk) = gen_p80211_fcdir((yyvsp[0].i)); }
#line 2871 "y.tab.c"
    break;

  case 134: /* type: ID  */
#line 538 "grammar.y"
                                { (yyval.i) = str2tok((yyvsp[0].s), ieee80211_types);
				  if ((yyval.i) == -1)
				  	bpf_error("unknown 802.11 type name");
				}
#line 2880 "y.tab.c"
    break;

  case 136: /* subtype: ID  */
#line 545 "grammar.y"
                                { const struct tok *types = NULL;
				  int i;
				  for (i = 0;; i++) {
				  	if (ieee80211_type_subtypes[i].tok == NULL) {
				  		/* Ran out of types */
						bpf_error("unknown 802.11 type");
						break;
					}
					if ((yyvsp[(-1) - (1)].i) == ieee80211_type_subtypes[i].type) {
						types = ieee80211_type_subtypes[i].tok;
						break;
					}
				  }

				  (yyval.i) = str2tok((yyvsp[0].s), types);
				  if ((yyval.i) == -1)
					bpf_error("unknown 802.11 subtype name");
				}
#line 2903 "y.tab.c"
    break;

  case 137: /* type_subtype: ID  */
#line 565 "grammar.y"
                                { int i;
				  for (i = 0;; i++) {
				  	if (ieee80211_type_subtypes[i].tok == NULL) {
				  		/* Ran out of types */
						bpf_error("unknown 802.11 type name");
						break;
					}
					(yyval.i) = str2tok((yyvsp[0].s), ieee80211_type_subtypes[i].tok);
					if ((yyval.i) != -1) {
						(yyval.i) |= ieee80211_type_subtypes[i].type;
						break;
					}
				  }
				}
#line 2922 "y.tab.c"
    break;

  case 139: /* dir: ID  */
#line 582 "grammar.y"
                                { if (pcap_strcasecmp((yyvsp[0].s), "nods") == 0)
					(yyval.i) = IEEE80211_FC1_DIR_NODS;
				  else if (pcap_strcasecmp((yyvsp[0].s), "tods") == 0)
					(yyval.i) = IEEE80211_FC1_DIR_TODS;
				  else if (pcap_strcasecmp((yyvsp[0].s), "fromds") == 0)
					(yyval.i) = IEEE80211_FC1_DIR_FROMDS;
				  else if (pcap_strcasecmp((yyvsp[0].s), "dstods") == 0)
					(yyval.i) = IEEE80211_FC1_DIR_DSTODS;
				  else
					bpf_error("unknown 802.11 direction");
				}
#line 2938 "y.tab.c"
    break;

  case 140: /* reason: NUM  */
#line 595 "grammar.y"
                                { (yyval.i) = (yyvsp[0].i); }
#line 2944 "y.tab.c"
    break;

  case 141: /* reason: ID  */
#line 596 "grammar.y"
                                { (yyval.i) = pfreason_to_num((yyvsp[0].s)); }
#line 2950 "y.tab.c"
    break;

  case 142: /* action: ID  */
#line 599 "grammar.y"
                                { (yyval.i) = pfaction_to_num((yyvsp[0].s)); }
#line 2956 "y.tab.c"
    break;

  case 143: /* relop: '>'  */
#line 602 "grammar.y"
                                { (yyval.i) = BPF_JGT; }
#line 2962 "y.tab.c"
    break;

  case 144: /* relop: GEQ  */
#line 603 "grammar.y"
                                { (yyval.i) = BPF_JGE; }
#line 2968 "y.tab.c"
    break;

  case 145: /* relop: '='  */
#line 604 "grammar.y"
                                { (yyval.i) = BPF_JEQ; }
#line 2974 "y.tab.c"
    break;

  case 146: /* irelop: LEQ  */
#line 606 "grammar.y"
                                { (yyval.i) = BPF_JGT; }
#line 2980 "y.tab.c"
    break;

  case 147: /* irelop: '<'  */
#line 607 "grammar.y"
                                { (yyval.i) = BPF_JGE; }
#line 2986 "y.tab.c"
    break;

  case 148: /* irelop: NEQ  */
#line 608 "grammar.y"
                                { (yyval.i) = BPF_JEQ; }
#line 2992 "y.tab.c"
    break;

  case 149: /* arth: pnum  */
#line 610 "grammar.y"
                                { (yyval.a) = gen_loadi((yyvsp[0].i)); }
#line 2998 "y.tab.c"
    break;

  case 151: /* narth: pname '[' arth ']'  */
#line 613 "grammar.y"
                                        { (yyval.a) = gen_load((yyvsp[-3].i), (yyvsp[-1].a), 1); }
#line 3004 "y.tab.c"
    break;

  case 152: /* narth: pname '[' arth ':' NUM ']'  */
#line 614 "grammar.y"
                                        { (yyval.a) = gen_load((yyvsp[-5].i), (yyvsp[-3].a), (yyvsp[-1].i)); }
#line 3010 "y.tab.c"
    break;

  case 153: /* narth: arth '+' arth  */
#line 615 "grammar.y"
                                        { (yyval.a) = gen_arth(BPF_ADD, (yyvsp[-2].a), (yyvsp[0].a)); }
#line 3016 "y.tab.c"
    break;

  case 154: /* narth: arth '-' arth  */
#line 616 "grammar.y"
                                        { (yyval.a) = gen_arth(BPF_SUB, (yyvsp[-2].a), (yyvsp[0].a)); }
#line 3022 "y.tab.c"
    break;

  case 155: /* narth: arth '*' arth  */
#line 617 "grammar.y"
                                        { (yyval.a) = gen_arth(BPF_MUL, (yyvsp[-2].a), (yyvsp[0].a)); }
#line 3028 "y.tab.c"
    break;

  case 156: /* narth: arth '/' arth  */
#line 618 "grammar.y"
                                        { (yyval.a) = gen_arth(BPF_DIV, (yyvsp[-2].a), (yyvsp[0].a)); }
#line 3034 "y.tab.c"
    break;

  case 157: /* narth: arth '&' arth  */
#line 619 "grammar.y"
                                        { (yyval.a) = gen_arth(BPF_AND, (yyvsp[-2].a), (yyvsp[0].a)); }
#line 3040 "y.tab.c"
    break;

  case 158: /* narth: arth '|' arth  */
#line 620 "grammar.y"
                                        { (yyval.a) = gen_arth(BPF_OR, (yyvsp[-2].a), (yyvsp[0].a)); }
#line 3046 "y.tab.c"
    break;

  case 159: /* narth: arth LSH arth  */
#line 621 "grammar.y"
                                        { (yyval.a) = gen_arth(BPF_LSH, (yyvsp[-2].a), (yyvsp[0].a)); }
#line 3052 "y.tab.c"
    break;

  case 160: /* narth: arth RSH arth  */
#line 622 "grammar.y"
                                        { (yyval.a) = gen_arth(BPF_RSH, (yyvsp[-2].a), (yyvsp[0].a)); }
#line 3058 "y.tab.c"
    break;

  case 161: /* narth: '-' arth  */
#line 623 "grammar.y"
                                        { (yyval.a) = gen_neg((yyvsp[0].a)); }
#line 3064 "y.tab.c"
    break;

  case 162: /* narth: paren narth ')'  */
#line 624 "grammar.y"
                                        { (yyval.a) = (yyvsp[-1].a); }
#line 3070 "y.tab.c"
    break;

  case 163: /* narth: LEN  */
#line 625 "grammar.y"
                                        { (yyval.a) = gen_loadlen(); }
#line 3076 "y.tab.c"
    break;

  case 164: /* byteop: '&'  */
#line 627 "grammar.y"
                                { (yyval.i) = '&'; }
#line 3082 "y.tab.c"
    break;

  case 165: /* byteop: '|'  */
#line 628 "grammar.y"
                                { (yyval.i) = '|'; }
#line 3088 "y.tab.c"
    break;

  case 166: /* byteop: '<'  */
#line 629 "grammar.y"
                                { (yyval.i) = '<'; }
#line 3094 "y.tab.c"
    break;

  case 167: /* byteop: '>'  */
#line 630 "grammar.y"
                                { (yyval.i) = '>'; }
#line 3100 "y.tab.c"
    break;

  case 168: /* byteop: '='  */
#line 631 "grammar.y"
                                { (yyval.i) = '='; }
#line 3106 "y.tab.c"
    break;

  case 170: /* pnum: paren pnum ')'  */
#line 634 "grammar.y"
                                { (yyval.i) = (yyvsp[-1].i); }
#line 3112 "y.tab.c"
    break;

  case 171: /* atmtype: LANE  */
#line 636 "grammar.y"
                                { (yyval.i) = A_LANE; }
#line 3118 "y.tab.c"
    break;

  case 172: /* atmtype: LLC  */
#line 637 "grammar.y"
                                { (yyval.i) = A_LLC; }
#line 3124 "y.tab.c"
    break;

  case 173: /* atmtype: METAC  */
#line 638 "grammar.y"
                                { (yyval.i) = A_METAC;	}
#line 3130 "y.tab.c"
    break;

  case 174: /* atmtype: BCC  */
#line 639 "grammar.y"
                                { (yyval.i) = A_BCC; }
#line 3136 "y.tab.c"
    break;

  case 175: /* atmtype: OAMF4EC  */
#line 640 "grammar.y"
                                { (yyval.i) = A_OAMF4EC; }
#line 3142 "y.tab.c"
    break;

  case 176: /* atmtype: OAMF4SC  */
#line 641 "grammar.y"
                                { (yyval.i) = A_OAMF4SC; }
#line 3148 "y.tab.c"
    break;

  case 177: /* atmtype: SC  */
#line 642 "grammar.y"
                                { (yyval.i) = A_SC; }
#line 3154 "y.tab.c"
    break;

  case 178: /* atmtype: ILMIC  */
#line 643 "grammar.y"
                                { (yyval.i) = A_ILMIC; }
#line 3160 "y.tab.c"
    break;

  case 179: /* atmmultitype: OAM  */
#line 645 "grammar.y"
                                { (yyval.i) = A_OAM; }
#line 3166 "y.tab.c"
    break;

  case 180: /* atmmultitype: OAMF4  */
#line 646 "grammar.y"
                                { (yyval.i) = A_OAMF4; }
#line 3172 "y.tab.c"
    break;

  case 181: /* atmmultitype: CONNECTMSG  */
#line 647 "grammar.y"
                                { (yyval.i) = A_CONNECTMSG; }
#line 3178 "y.tab.c"
    break;

  case 182: /* atmmultitype: METACONNECT  */
#line 648 "grammar.y"
                                { (yyval.i) = A_METACONNECT; }
#line 3184 "y.tab.c"
    break;

  case 183: /* atmfield: VPI  */
#line 651 "grammar.y"
                                { (yyval.blk).atmfieldtype = A_VPI; }
#line 3190 "y.tab.c"
    break;

  case 184: /* atmfield: VCI  */
#line 652 "grammar.y"
                                { (yyval.blk).atmfieldtype = A_VCI; }
#line 3196 "y.tab.c"
    break;

  case 186: /* atmvalue: relop NUM  */
#line 655 "grammar.y"
                                { (yyval.blk).b = gen_atmfield_code((yyvsp[-2].blk).atmfieldtype, (bpf_int32)(yyvsp[0].i), (bpf_u_int32)(yyvsp[-1].i), 0); }
#line 3202 "y.tab.c"
    break;

  case 187: /* atmvalue: irelop NUM  */
#line 656 "grammar.y"
                                { (yyval.blk).b = gen_atmfield_code((yyvsp[-2].blk).atmfieldtype, (bpf_int32)(yyvsp[0].i), (bpf_u_int32)(yyvsp[-1].i), 1); }
#line 3208 "y.tab.c"
    break;

  case 188: /* atmvalue: paren atmlistvalue ')'  */
#line 657 "grammar.y"
                                 { (yyval.blk).b = (yyvsp[-1].blk).b; (yyval.blk).q = qerr; }
#line 3214 "y.tab.c"
    break;

  case 189: /* atmfieldvalue: NUM  */
#line 659 "grammar.y"
                   {
	(yyval.blk).atmfieldtype = (yyvsp[-1].blk).atmfieldtype;
	if ((yyval.blk).atmfieldtype == A_VPI ||
	    (yyval.blk).atmfieldtype == A_VCI)
		(yyval.blk).b = gen_atmfield_code((yyval.blk).atmfieldtype, (bpf_int32) (yyvsp[0].i), BPF_JEQ, 0);
	}
#line 3225 "y.tab.c"
    break;

  case 191: /* atmlistvalue: atmlistvalue or atmfieldvalue  */
#line 667 "grammar.y"
                                        { gen_or((yyvsp[-2].blk).b, (yyvsp[0].blk).b); (yyval.blk) = (yyvsp[0].blk); }
#line 3231 "y.tab.c"
    break;

  case 192: /* mtp2type: FISU  */
#line 670 "grammar.y"
                                { (yyval.i) = M_FISU; }
#line 3237 "y.tab.c"
    break;

  case 193: /* mtp2type: LSSU  */
#line 671 "grammar.y"
                                { (yyval.i) = M_LSSU; }
#line 3243 "y.tab.c"
    break;

  case 194: /* mtp2type: MSU  */
#line 672 "grammar.y"
                                { (yyval.i) = M_MSU; }
#line 3249 "y.tab.c"
    break;

  case 195: /* mtp3field: SIO  */
#line 675 "grammar.y"
                                { (yyval.blk).mtp3fieldtype = M_SIO; }
#line 3255 "y.tab.c"
    break;

  case 196: /* mtp3field: OPC  */
#line 676 "grammar.y"
                                { (yyval.blk).mtp3fieldtype = M_OPC; }
#line 3261 "y.tab.c"
    break;

  case 197: /* mtp3field: DPC  */
#line 677 "grammar.y"
                                { (yyval.blk).mtp3fieldtype = M_DPC; }
#line 3267 "y.tab.c"
    break;

  case 198: /* mtp3field: SLS  */
#line 678 "grammar.y"
                                { (yyval.blk).mtp3fieldtype = M_SLS; }
#line 3273 "y.tab.c"
    break;

  case 200: /* mtp3value: relop NUM  */
#line 681 "grammar.y"
                                { (yyval.blk).b = gen_mtp3field_code((yyvsp[-2].blk).mtp3fieldtype, (u_int)(yyvsp[0].i), (u_int)(yyvsp[-1].i), 0); }
#line 3279 "y.tab.c"
    break;

  case 201: /* mtp3value: irelop NUM  */
#line 682 "grammar.y"
                                { (yyval.blk).b = gen_mtp3field_code((yyvsp[-2].blk).mtp3fieldtype, (u_int)(yyvsp[0].i), (u_int)(yyvsp[-1].i), 1); }
#line 3285 "y.tab.c"
    break;

  case 202: /* mtp3value: paren mtp3listvalue ')'  */
#line 683 "grammar.y"
                                  { (yyval.blk).b = (yyvsp[-1].blk).b; (yyval.blk).q = qerr; }
#line 3291 "y.tab.c"
    break;

  case 203: /* mtp3fieldvalue: NUM  */
#line 685 "grammar.y"
                    {
	(yyval.blk).mtp3fieldtype = (yyvsp[-1].blk).mtp3fieldtype;
	if ((yyval.blk).mtp3fieldtype == M_SIO ||
	    (yyval.blk).mtp3fieldtype == M_OPC ||
	    (yyval.blk).mtp3fieldtype == M_DPC ||
	    (yyval.blk).mtp3fieldtype == M_SLS )
		(yyval.blk).b = gen_mtp3field_code((yyval.blk).mtp3fieldtype, (u_int) (yyvsp[0].i), BPF_JEQ, 0);
	}
#line 3304 "y.tab.c"
    break;

  case 205: /* mtp3listvalue: mtp3listvalue or mtp3fieldvalue  */
#line 695 "grammar.y"
                                          { gen_or((yyvsp[-2].blk).b, (yyvsp[0].blk).b); (yyval.blk) = (yyvsp[0].blk); }
#line 3310 "y.tab.c"
    break;


#line 3314 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 697 "grammar.y"

