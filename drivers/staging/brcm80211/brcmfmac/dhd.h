/*
 * Copyright (c) 2010 Broadcom Corporation
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
 * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/****************
 * Common types *
 */

#ifndef _dhd_h_
#define _dhd_h_

/* Forward decls */
struct dhd_bus;
struct dhd_prot;
struct dhd_info;

#define WLC_UP					2
#define WLC_SET_PROMISC				10
#define WLC_GET_RATE				12
#define WLC_GET_INFRA				19
#define WLC_SET_INFRA				20
#define WLC_GET_AUTH				21
#define WLC_SET_AUTH				22
#define WLC_GET_BSSID				23
#define WLC_GET_SSID				25
#define WLC_SET_SSID				26
#define WLC_GET_CHANNEL				29
#define WLC_GET_SRL				31
#define WLC_GET_LRL				33
#define WLC_GET_RADIO				37
#define WLC_SET_RADIO				38
#define WLC_GET_PHYTYPE				39
#define WLC_SET_KEY				45
#define WLC_SET_PASSIVE_SCAN			49
#define WLC_SCAN				50
#define WLC_SCAN_RESULTS			51
#define WLC_DISASSOC				52
#define WLC_REASSOC				53
#define WLC_SET_ROAM_TRIGGER			55
#define WLC_SET_ROAM_DELTA			57
#define WLC_GET_DTIMPRD				77
#define WLC_SET_COUNTRY				84
#define WLC_GET_PM				85
#define WLC_SET_PM				86
#define WLC_GET_AP				117
#define WLC_SET_AP				118
#define WLC_GET_RSSI				127
#define WLC_GET_WSEC				133
#define WLC_SET_WSEC				134
#define WLC_GET_PHY_NOISE			135
#define WLC_GET_BSS_INFO			136
#define WLC_SET_SCAN_CHANNEL_TIME		185
#define WLC_SET_SCAN_UNASSOC_TIME		187
#define WLC_SCB_DEAUTHENTICATE_FOR_REASON	201
#define WLC_GET_VALID_CHANNELS			217
#define WLC_GET_KEY_PRIMARY			235
#define WLC_SET_KEY_PRIMARY			236
#define WLC_SET_SCAN_PASSIVE_TIME		258
#define WLC_GET_VAR				262	/* get value of named variable */
#define WLC_SET_VAR				263	/* set named variable to value */

/* phy types (returned by WLC_GET_PHYTPE) */
#define	WLC_PHY_TYPE_A		0
#define	WLC_PHY_TYPE_B		1
#define	WLC_PHY_TYPE_G		2
#define	WLC_PHY_TYPE_N		4
#define	WLC_PHY_TYPE_LP		5
#define	WLC_PHY_TYPE_SSN	6
#define	WLC_PHY_TYPE_HT		7
#define	WLC_PHY_TYPE_LCN	8
#define	WLC_PHY_TYPE_NULL	0xf

#define WL_PKT_FILTER_FIXED_LEN		  offsetof(wl_pkt_filter_t, u)
#define WL_PKT_FILTER_PATTERN_FIXED_LEN	  offsetof(wl_pkt_filter_pattern_t, mask_and_pattern)

#define WL_EVENTING_MASK_LEN	16

#define TOE_TX_CSUM_OL		0x00000001
#define TOE_RX_CSUM_OL		0x00000002

/* maximum channels returned by the get valid channels iovar */
#define WL_NUMCHANNELS		64

#define	WL_BSS_INFO_VERSION	108	/* current ver of wl_bss_info struct */

/* size of wl_scan_params not including variable length array */
#define WL_SCAN_PARAMS_FIXED_SIZE 64

/* masks for channel and ssid count */
#define WL_SCAN_PARAMS_COUNT_MASK 0x0000ffff
#define WL_SCAN_PARAMS_NSSID_SHIFT 16

#define WL_SCAN_ACTION_START      1
#define WL_SCAN_ACTION_CONTINUE   2
#define WL_SCAN_ACTION_ABORT      3

#define ISCAN_REQ_VERSION 1

/* wl_iscan_results status values */
#define WL_SCAN_RESULTS_SUCCESS	0
#define WL_SCAN_RESULTS_PARTIAL	1
#define WL_SCAN_RESULTS_PENDING	2
#define WL_SCAN_RESULTS_ABORTED	3
#define WL_SCAN_RESULTS_NO_MEM	4

#define MAX_CCA_CHANNELS 38	/* Max number of 20 Mhz wide channels */
#define MAX_CCA_SECS     60	/* CCA keeps this many seconds history */

#define IBSS_MED        15	/* Mediom in-bss congestion percentage */
#define IBSS_HI         25	/* Hi in-bss congestion percentage */
#define OBSS_MED        12
#define OBSS_HI         25
#define INTERFER_MED    5
#define INTERFER_HI     10

#define  CCA_FLAG_2G_ONLY		0x01	/* Return a channel from 2.4 Ghz band */
#define  CCA_FLAG_5G_ONLY		0x02	/* Return a channel from 2.4 Ghz band */
#define  CCA_FLAG_IGNORE_DURATION	0x04	/* Ignore dwell time for each channel */
#define  CCA_FLAGS_PREFER_1_6_11	0x10
#define  CCA_FLAG_IGNORE_INTERFER 	0x20	/* do not exlude channel based on interfer level */

#define CCA_ERRNO_BAND 		1	/* After filtering for band pref, no choices left */
#define CCA_ERRNO_DURATION	2	/* After filtering for duration, no choices left */
#define CCA_ERRNO_PREF_CHAN	3	/* After filtering for chan pref, no choices left */
#define CCA_ERRNO_INTERFER	4	/* After filtering for interference, no choices left */
#define CCA_ERRNO_TOO_FEW	5	/* Only 1 channel was input */

#define WL_NUM_RPI_BINS		8
#define WL_RM_TYPE_BASIC	1
#define WL_RM_TYPE_CCA		2
#define WL_RM_TYPE_RPI		3

#define WL_RM_FLAG_PARALLEL	(1<<0)

#define WL_RM_FLAG_LATE		(1<<1)
#define WL_RM_FLAG_INCAPABLE	(1<<2)
#define WL_RM_FLAG_REFUSED	(1<<3)

#define WL_SOFT_KEY	(1 << 0)	/* Indicates this key is using soft encrypt */
#define WL_PRIMARY_KEY	(1 << 1)	/* Indicates this key is the primary (ie tx) key */
#define WL_KF_RES_4	(1 << 4)	/* Reserved for backward compat */
#define WL_KF_RES_5	(1 << 5)	/* Reserved for backward compat */
#define WL_IBSS_PEER_GROUP_KEY	(1 << 6)	/* Indicates a group key for a IBSS PEER */

#define	WLC_IOCTL_SMLEN			256	/* "small" length ioctl buffer required */
#define WLC_IOCTL_MEDLEN		1536	/* "med" length ioctl buffer required */
#define	WLC_IOCTL_MAXLEN	8192

#define DHD_IF_VIF	0x01	/* Virtual IF (Hidden from user) */

/* optionally set by a module_param_string() */
#define MOD_PARAM_PATHLEN	2048

/* For supporting multiple interfaces */
#define DHD_MAX_IFS	16
#define DHD_DEL_IF	-0xe
#define DHD_BAD_IF	-0xf

#define DOT11_BSSTYPE_ANY			2
#define DOT11_MAX_DEFAULT_KEYS	4

#define BCM_EVENT_MSG_VERSION		1
#define BCM_MSG_IFNAME_MAX		16

#define WLC_EVENT_MSG_LINK		0x01
#define WLC_EVENT_MSG_FLUSHTXQ		0x02
#define WLC_EVENT_MSG_GROUP		0x04

typedef struct {
	u16 version;
	u16 flags;
	u32 event_type;
	u32 status;
	u32 reason;
	u32 auth_type;
	u32 datalen;
	u8 addr[ETH_ALEN];
	char ifname[BCM_MSG_IFNAME_MAX];
} __attribute__((packed)) wl_event_msg_t;

typedef  struct bcmeth_hdr {
	u16 subtype;
	u16 length;
	u8 version;
	u8 oui[3];
	u16 usr_subtype;
} __attribute__((packed)) bcmeth_hdr_t;

#ifdef BRCM_FULLMAC
typedef struct bcm_event {
	struct ethhdr eth;
	bcmeth_hdr_t		bcm_hdr;
	wl_event_msg_t		event;
} __attribute__((packed)) bcm_event_t;
#endif
#define BCM_MSG_LEN	(sizeof(bcm_event_t) - sizeof(bcmeth_hdr_t) - \
	sizeof(struct ether_header))

#define WLC_E_SET_SSID		0
#define WLC_E_JOIN		1
#define WLC_E_START		2
#define WLC_E_AUTH		3
#define WLC_E_AUTH_IND		4
#define WLC_E_DEAUTH		5
#define WLC_E_DEAUTH_IND	6
#define WLC_E_ASSOC		7
#define WLC_E_ASSOC_IND		8
#define WLC_E_REASSOC		9
#define WLC_E_REASSOC_IND	10
#define WLC_E_DISASSOC		11
#define WLC_E_DISASSOC_IND	12
#define WLC_E_QUIET_START	13
#define WLC_E_QUIET_END		14
#define WLC_E_BEACON_RX		15
#define WLC_E_LINK		16
#define WLC_E_MIC_ERROR		17
#define WLC_E_NDIS_LINK		18
#define WLC_E_ROAM		19
#define WLC_E_TXFAIL		20
#define WLC_E_PMKID_CACHE	21
#define WLC_E_RETROGRADE_TSF	22
#define WLC_E_PRUNE		23
#define WLC_E_AUTOAUTH		24
#define WLC_E_EAPOL_MSG		25
#define WLC_E_SCAN_COMPLETE	26
#define WLC_E_ADDTS_IND		27
#define WLC_E_DELTS_IND		28
#define WLC_E_BCNSENT_IND	29
#define WLC_E_BCNRX_MSG		30
#define WLC_E_BCNLOST_MSG	31
#define WLC_E_ROAM_PREP		32
#define WLC_E_PFN_NET_FOUND	33
#define WLC_E_PFN_NET_LOST	34
#define WLC_E_RESET_COMPLETE	35
#define WLC_E_JOIN_START	36
#define WLC_E_ROAM_START	37
#define WLC_E_ASSOC_START	38
#define WLC_E_IBSS_ASSOC	39
#define WLC_E_RADIO		40
#define WLC_E_PSM_WATCHDOG	41
#define WLC_E_PROBREQ_MSG       44
#define WLC_E_SCAN_CONFIRM_IND  45
#define WLC_E_PSK_SUP		46
#define WLC_E_COUNTRY_CODE_CHANGED 47
#define	WLC_E_EXCEEDED_MEDIUM_TIME 48
#define WLC_E_ICV_ERROR		49
#define WLC_E_UNICAST_DECODE_ERROR 50
#define WLC_E_MULTICAST_DECODE_ERROR 51
#define WLC_E_TRACE		52
#define WLC_E_IF		54
#define WLC_E_RSSI		56
#define WLC_E_PFN_SCAN_COMPLETE	57
#define WLC_E_EXTLOG_MSG	58
#define WLC_E_ACTION_FRAME      59
#define WLC_E_ACTION_FRAME_COMPLETE 60
#define WLC_E_PRE_ASSOC_IND	61
#define WLC_E_PRE_REASSOC_IND	62
#define WLC_E_CHANNEL_ADOPTED	63
#define WLC_E_AP_STARTED	64
#define WLC_E_DFS_AP_STOP	65
#define WLC_E_DFS_AP_RESUME	66
#define WLC_E_RESERVED1		67
#define WLC_E_RESERVED2		68
#define WLC_E_ESCAN_RESULT 	69
#define WLC_E_ACTION_FRAME_OFF_CHAN_COMPLETE 	70
#define WLC_E_DCS_REQUEST 73

#define WLC_E_FIFO_CREDIT_MAP	74

#define WLC_E_LAST		75

#define WLC_E_STATUS_SUCCESS		0
#define WLC_E_STATUS_FAIL		1
#define WLC_E_STATUS_TIMEOUT		2
#define WLC_E_STATUS_NO_NETWORKS	3
#define WLC_E_STATUS_ABORT		4
#define WLC_E_STATUS_NO_ACK		5
#define WLC_E_STATUS_UNSOLICITED	6
#define WLC_E_STATUS_ATTEMPT		7
#define WLC_E_STATUS_PARTIAL		8
#define WLC_E_STATUS_NEWSCAN		9
#define WLC_E_STATUS_NEWASSOC		10
#define WLC_E_STATUS_11HQUIET		11
#define WLC_E_STATUS_SUPPRESS		12
#define WLC_E_STATUS_NOCHANS		13
#define WLC_E_STATUS_CS_ABORT		15
#define WLC_E_STATUS_ERROR		16

#define WLC_E_REASON_INITIAL_ASSOC	0
#define WLC_E_REASON_LOW_RSSI		1
#define WLC_E_REASON_DEAUTH		2
#define WLC_E_REASON_DISASSOC		3
#define WLC_E_REASON_BCNS_LOST		4
#define WLC_E_REASON_MINTXRATE		9
#define WLC_E_REASON_TXFAIL		10

#define WLC_E_REASON_FAST_ROAM_FAILED	5
#define WLC_E_REASON_DIRECTED_ROAM	6
#define WLC_E_REASON_TSPEC_REJECTED	7
#define WLC_E_REASON_BETTER_AP		8

#define WLC_E_PRUNE_ENCR_MISMATCH	1
#define WLC_E_PRUNE_BCAST_BSSID		2
#define WLC_E_PRUNE_MAC_DENY		3
#define WLC_E_PRUNE_MAC_NA		4
#define WLC_E_PRUNE_REG_PASSV		5
#define WLC_E_PRUNE_SPCT_MGMT		6
#define WLC_E_PRUNE_RADAR		7
#define WLC_E_RSN_MISMATCH		8
#define WLC_E_PRUNE_NO_COMMON_RATES	9
#define WLC_E_PRUNE_BASIC_RATES		10
#define WLC_E_PRUNE_CIPHER_NA		12
#define WLC_E_PRUNE_KNOWN_STA		13
#define WLC_E_PRUNE_WDS_PEER		15
#define WLC_E_PRUNE_QBSS_LOAD		16
#define WLC_E_PRUNE_HOME_AP		17

#define WLC_E_SUP_OTHER			0
#define WLC_E_SUP_DECRYPT_KEY_DATA	1
#define WLC_E_SUP_BAD_UCAST_WEP128	2
#define WLC_E_SUP_BAD_UCAST_WEP40	3
#define WLC_E_SUP_UNSUP_KEY_LEN		4
#define WLC_E_SUP_PW_KEY_CIPHER		5
#define WLC_E_SUP_MSG3_TOO_MANY_IE	6
#define WLC_E_SUP_MSG3_IE_MISMATCH	7
#define WLC_E_SUP_NO_INSTALL_FLAG	8
#define WLC_E_SUP_MSG3_NO_GTK		9
#define WLC_E_SUP_GRP_KEY_CIPHER	10
#define WLC_E_SUP_GRP_MSG1_NO_GTK	11
#define WLC_E_SUP_GTK_DECRYPT_FAIL	12
#define WLC_E_SUP_SEND_FAIL		13
#define WLC_E_SUP_DEAUTH		14

#define WLC_E_IF_ADD		1
#define WLC_E_IF_DEL		2
#define WLC_E_IF_CHANGE		3

#define WLC_E_IF_ROLE_STA		0
#define WLC_E_IF_ROLE_AP		1
#define WLC_E_IF_ROLE_WDS		2

#define WLC_E_LINK_BCN_LOSS	1
#define WLC_E_LINK_DISASSOC	2
#define WLC_E_LINK_ASSOC_REC	3
#define WLC_E_LINK_BSSCFG_DIS	4

enum cust_gpio_modes {
	WLAN_RESET_ON,
	WLAN_RESET_OFF,
	WLAN_POWER_ON,
	WLAN_POWER_OFF
};

/* The level of bus communication with the dongle */
enum dhd_bus_state {
	DHD_BUS_DOWN,		/* Not ready for frame transfers */
	DHD_BUS_LOAD,		/* Download access only (CPU reset) */
	DHD_BUS_DATA		/* Ready for frame transfers */
};

/* Pattern matching filter. Specifies an offset within received packets to
 * start matching, the pattern to match, the size of the pattern, and a bitmask
 * that indicates which bits within the pattern should be matched.
 */
typedef struct wl_pkt_filter_pattern {
	u32 offset;		/* Offset within received packet to start pattern matching.
				 * Offset '0' is the first byte of the ethernet header.
				 */
	u32 size_bytes;	/* Size of the pattern.  Bitmask must be the same size. */
	u8 mask_and_pattern[1];	/* Variable length mask and pattern data.  mask starts
					 * at offset 0.  Pattern immediately follows mask.
					 */
} wl_pkt_filter_pattern_t;

/* IOVAR "pkt_filter_add" parameter. Used to install packet filters. */
typedef struct wl_pkt_filter {
	u32 id;		/* Unique filter id, specified by app. */
	u32 type;		/* Filter type (WL_PKT_FILTER_TYPE_xxx). */
	u32 negate_match;	/* Negate the result of filter matches */
	union {			/* Filter definitions */
		wl_pkt_filter_pattern_t pattern;	/* Pattern matching filter */
	} u;
} wl_pkt_filter_t;

/* IOVAR "pkt_filter_enable" parameter. */
typedef struct wl_pkt_filter_enable {
	u32 id;		/* Unique filter id */
	u32 enable;		/* Enable/disable bool */
} wl_pkt_filter_enable_t;

/* BSS info structure
 * Applications MUST CHECK ie_offset field and length field to access IEs and
 * next bss_info structure in a vector (in wl_scan_results_t)
 */
typedef struct wl_bss_info {
	u32 version;		/* version field */
	u32 length;		/* byte length of data in this record,
				 * starting at version and including IEs
				 */
	u8 BSSID[ETH_ALEN];
	u16 beacon_period;	/* units are Kusec */
	u16 capability;	/* Capability information */
	u8 SSID_len;
	u8 SSID[32];
	struct {
		uint count;	/* # rates in this set */
		u8 rates[16];	/* rates in 500kbps units w/hi bit set if basic */
	} rateset;		/* supported rates */
	chanspec_t chanspec;	/* chanspec for bss */
	u16 atim_window;	/* units are Kusec */
	u8 dtim_period;	/* DTIM period */
	s16 RSSI;		/* receive signal strength (in dBm) */
	s8 phy_noise;		/* noise (in dBm) */

	u8 n_cap;		/* BSS is 802.11N Capable */
	u32 nbss_cap;	/* 802.11N BSS Capabilities (based on HT_CAP_*) */
	u8 ctl_ch;		/* 802.11N BSS control channel number */
	u32 reserved32[1];	/* Reserved for expansion of BSS properties */
	u8 flags;		/* flags */
	u8 reserved[3];	/* Reserved for expansion of BSS properties */
	u8 basic_mcs[MCSSET_LEN];	/* 802.11N BSS required MCS set */

	u16 ie_offset;	/* offset at which IEs start, from beginning */
	u32 ie_length;	/* byte length of Information Elements */
	s16 SNR;		/* average SNR of during frame reception */
	/* Add new fields here */
	/* variable length Information Elements */
} wl_bss_info_t;

typedef struct wlc_ssid {
	u32 SSID_len;
	unsigned char SSID[32];
} wlc_ssid_t;

typedef struct wl_scan_params {
	wlc_ssid_t ssid;	/* default: {0, ""} */
	u8 bssid[ETH_ALEN];	/* default: bcast */
	s8 bss_type;		/* default: any,
				 * DOT11_BSSTYPE_ANY/INFRASTRUCTURE/INDEPENDENT
				 */
	u8 scan_type;	/* flags, 0 use default */
	s32 nprobes;		/* -1 use default, number of probes per channel */
	s32 active_time;	/* -1 use default, dwell time per channel for
				 * active scanning
				 */
	s32 passive_time;	/* -1 use default, dwell time per channel
				 * for passive scanning
				 */
	s32 home_time;	/* -1 use default, dwell time for the home channel
				 * between channel scans
				 */
	s32 channel_num;	/* count of channels and ssids that follow
				 *
				 * low half is count of channels in channel_list, 0
				 * means default (use all available channels)
				 *
				 * high half is entries in wlc_ssid_t array that
				 * follows channel_list, aligned for s32 (4 bytes)
				 * meaning an odd channel count implies a 2-byte pad
				 * between end of channel_list and first ssid
				 *
				 * if ssid count is zero, single ssid in the fixed
				 * parameter portion is assumed, otherwise ssid in
				 * the fixed portion is ignored
				 */
	u16 channel_list[1];	/* list of chanspecs */
} wl_scan_params_t;

/* incremental scan struct */
typedef struct wl_iscan_params {
	u32 version;
	u16 action;
	u16 scan_duration;
	wl_scan_params_t params;
} wl_iscan_params_t;

/* 3 fields + size of wl_scan_params, not including variable length array */
#define WL_ISCAN_PARAMS_FIXED_SIZE (offsetof(wl_iscan_params_t, params) + sizeof(wlc_ssid_t))

typedef struct wl_scan_results {
	u32 buflen;
	u32 version;
	u32 count;
	wl_bss_info_t bss_info[1];
} wl_scan_results_t;

typedef struct wl_rateset_args {
	u32 count;		/* # rates in this set */
	u8 rates[WL_NUMRATES];	/* rates in 500kbps units w/hi bit set if basic */
	u8 mcs[MCSSET_LEN];	/* supported mcs index bit map */
} wl_rateset_args_t;

/* u32 list */
typedef struct wl_u32_list {
	/* in - # of elements, out - # of entries */
	u32 count;
	/* variable length u32 list */
	u32 element[1];
} wl_u32_list_t;

/* used for association with a specific BSSID and chanspec list */
typedef struct wl_assoc_params {
	u8 bssid[ETH_ALEN];	/* 00:00:00:00:00:00: broadcast scan */
	s32 chanspec_num;	/* 0: all available channels,
				 * otherwise count of chanspecs in chanspec_list
				 */
	chanspec_t chanspec_list[1];	/* list of chanspecs */
} wl_assoc_params_t;
#define WL_ASSOC_PARAMS_FIXED_SIZE 	(sizeof(wl_assoc_params_t) - sizeof(chanspec_t))

/* used for reassociation/roam to a specific BSSID and channel */
typedef wl_assoc_params_t wl_reassoc_params_t;
#define WL_REASSOC_PARAMS_FIXED_SIZE	WL_ASSOC_PARAMS_FIXED_SIZE

/* used for join with or without a specific bssid and channel list */
typedef struct wl_join_params {
	wlc_ssid_t ssid;
	wl_assoc_params_t params;	/* optional field, but it must include the fixed portion
					 * of the wl_assoc_params_t struct when it does present.
					 */
} wl_join_params_t;
#define WL_JOIN_PARAMS_FIXED_SIZE 	(sizeof(wl_join_params_t) - sizeof(chanspec_t))

/* size of wl_scan_results not including variable length array */
#define WL_SCAN_RESULTS_FIXED_SIZE (sizeof(wl_scan_results_t) - sizeof(wl_bss_info_t))

/* incremental scan results struct */
typedef struct wl_iscan_results {
	u32 status;
	wl_scan_results_t results;
} wl_iscan_results_t;

/* size of wl_iscan_results not including variable length array */
#define WL_ISCAN_RESULTS_FIXED_SIZE \
	(WL_SCAN_RESULTS_FIXED_SIZE + offsetof(wl_iscan_results_t, results))

typedef struct {
	u32 duration;	/* millisecs spent sampling this channel */
	u32 congest_ibss;	/* millisecs in our bss (presumably this traffic will */
	/*  move if cur bss moves channels) */
	u32 congest_obss;	/* traffic not in our bss */
	u32 interference;	/* millisecs detecting a non 802.11 interferer. */
	u32 timestamp;	/* second timestamp */
} cca_congest_t;

typedef struct {
	chanspec_t chanspec;	/* Which channel? */
	u8 num_secs;		/* How many secs worth of data */
	cca_congest_t secs[1];	/* Data */
} cca_congest_channel_req_t;

typedef struct wl_country {
	char country_abbrev[WLC_CNTRY_BUF_SZ];	/* nul-terminated country code used in
						 * the Country IE
						 */
	s32 rev;		/* revision specifier for ccode
				 * on set, -1 indicates unspecified.
				 * on get, rev >= 0
				 */
	char ccode[WLC_CNTRY_BUF_SZ];	/* nul-terminated built-in country code.
					 * variable length, but fixed size in
					 * struct allows simple allocation for
					 * expected country strings <= 3 chars.
					 */
} wl_country_t;

typedef struct wl_channels_in_country {
	u32 buflen;
	u32 band;
	char country_abbrev[WLC_CNTRY_BUF_SZ];
	u32 count;
	u32 channel[1];
} wl_channels_in_country_t;

typedef struct wl_country_list {
	u32 buflen;
	u32 band_set;
	u32 band;
	u32 count;
	char country_abbrev[1];
} wl_country_list_t;

typedef struct wl_rm_req_elt {
	s8 type;
	s8 flags;
	chanspec_t chanspec;
	u32 token;		/* token for this measurement */
	u32 tsf_h;		/* TSF high 32-bits of Measurement start time */
	u32 tsf_l;		/* TSF low 32-bits */
	u32 dur;		/* TUs */
} wl_rm_req_elt_t;

typedef struct wl_rm_req {
	u32 token;		/* overall measurement set token */
	u32 count;		/* number of measurement requests */
	void *cb;		/* completion callback function: may be NULL */
	void *cb_arg;		/* arg to completion callback function */
	wl_rm_req_elt_t req[1];	/* variable length block of requests */
} wl_rm_req_t;
#define WL_RM_REQ_FIXED_LEN	offsetof(wl_rm_req_t, req)

typedef struct wl_rm_rep_elt {
	s8 type;
	s8 flags;
	chanspec_t chanspec;
	u32 token;		/* token for this measurement */
	u32 tsf_h;		/* TSF high 32-bits of Measurement start time */
	u32 tsf_l;		/* TSF low 32-bits */
	u32 dur;		/* TUs */
	u32 len;		/* byte length of data block */
	u8 data[1];		/* variable length data block */
} wl_rm_rep_elt_t;
#define WL_RM_REP_ELT_FIXED_LEN	24	/* length excluding data block */

#define WL_RPI_REP_BIN_NUM 8
typedef struct wl_rm_rpi_rep {
	u8 rpi[WL_RPI_REP_BIN_NUM];
	s8 rpi_max[WL_RPI_REP_BIN_NUM];
} wl_rm_rpi_rep_t;

typedef struct wl_rm_rep {
	u32 token;		/* overall measurement set token */
	u32 len;		/* length of measurement report block */
	wl_rm_rep_elt_t rep[1];	/* variable length block of reports */
} wl_rm_rep_t;
#define WL_RM_REP_FIXED_LEN	8

typedef struct wl_wsec_key {
	u32 index;		/* key index */
	u32 len;		/* key length */
	u8 data[WLAN_MAX_KEY_LEN];	/* key data */
	u32 pad_1[18];
	u32 algo;		/* CRYPTO_ALGO_AES_CCM, CRYPTO_ALGO_WEP128, etc */
	u32 flags;		/* misc flags */
	u32 pad_2[2];
	int pad_3;
	int iv_initialized;	/* has IV been initialized already? */
	int pad_4;
	/* Rx IV */
	struct {
		u32 hi;	/* upper 32 bits of IV */
		u16 lo;	/* lower 16 bits of IV */
	} rxiv;
	u32 pad_5[2];
	u8 ea[ETH_ALEN];	/* per station */
} wl_wsec_key_t;

/* Used to get specific STA parameters */
typedef struct {
	u32 val;
	u8 ea[ETH_ALEN];
} scb_val_t;

/* channel encoding */
typedef struct channel_info {
	int hw_channel;
	int target_channel;
	int scan_channel;
} channel_info_t;

/* Linux network driver ioctl encoding */
typedef struct wl_ioctl {
	uint cmd;		/* common ioctl definition */
	void *buf;		/* pointer to user buffer */
	uint len;		/* length of user buffer */
	u8 set;		/* get or set request (optional) */
	uint used;		/* bytes read or written (optional) */
	uint needed;		/* bytes needed (optional) */
} wl_ioctl_t;

/* Common structure for module and instance linkage */
typedef struct dhd_pub {
	/* Linkage ponters */
	struct dhd_bus *bus;	/* Bus module handle */
	struct dhd_prot *prot;	/* Protocol module handle */
	struct dhd_info *info;	/* Info module handle */

	/* Internal dhd items */
	bool up;		/* Driver up/down (to OS) */
	bool txoff;		/* Transmit flow-controlled */
	bool dongle_reset;	/* true = DEVRESET put dongle into reset */
	enum dhd_bus_state busstate;
	uint hdrlen;		/* Total DHD header length (proto + bus) */
	uint maxctl;		/* Max size rxctl request from proto to bus */
	uint rxsz;		/* Rx buffer size bus module should use */
	u8 wme_dp;		/* wme discard priority */

	/* Dongle media info */
	bool iswl;		/* Dongle-resident driver is wl */
	unsigned long drv_version;	/* Version of dongle-resident driver */
	u8 mac[ETH_ALEN];			/* MAC address obtained from dongle */
	dngl_stats_t dstats;		/* Stats for dongle-based data */

	/* Additional stats for the bus level */
	unsigned long tx_packets;	/* Data packets sent to dongle */
	unsigned long tx_multicast;	/* Multicast data packets sent to dongle */
	unsigned long tx_errors;	/* Errors in sending data to dongle */
	unsigned long tx_ctlpkts;	/* Control packets sent to dongle */
	unsigned long tx_ctlerrs;	/* Errors sending control frames to dongle */
	unsigned long rx_packets;	/* Packets sent up the network interface */
	unsigned long rx_multicast;	/* Multicast packets sent up the network
					 interface */
	unsigned long rx_errors;	/* Errors processing rx data packets */
	unsigned long rx_ctlpkts;	/* Control frames processed from dongle */
	unsigned long rx_ctlerrs;	/* Errors in processing rx control frames */
	unsigned long rx_dropped;	/* Packets dropped locally (no memory) */
	unsigned long rx_flushed;	/* Packets flushed due to
				unscheduled sendup thread */
	unsigned long wd_dpc_sched;	/* Number of times dhd dpc scheduled by
					 watchdog timer */

	unsigned long rx_readahead_cnt;	/* Number of packets where header read-ahead
					 was used. */
	unsigned long tx_realloc;	/* Number of tx packets we had to realloc for
					 headroom */
	unsigned long fc_packets;	/* Number of flow control pkts recvd */

	/* Last error return */
	int bcmerror;
	uint tickcnt;

	/* Last error from dongle */
	int dongle_error;

	/* Suspend disable flag  flag */
	int suspend_disable_flag;	/* "1" to disable all extra powersaving
					 during suspend */
	int in_suspend;		/* flag set to 1 when early suspend called */
#ifdef PNO_SUPPORT
	int pno_enable;		/* pno status : "1" is pno enable */
#endif				/* PNO_SUPPORT */
	int dtim_skip;		/* dtim skip , default 0 means wake each dtim */

	/* Pkt filter defination */
	char *pktfilter[100];
	int pktfilter_count;

	u8 country_code[WLC_CNTRY_BUF_SZ];
	char eventmask[WL_EVENTING_MASK_LEN];

} dhd_pub_t;

typedef struct dhd_if_event {
	u8 ifidx;
	u8 action;
	u8 flags;
	u8 bssidx;
} dhd_if_event_t;

typedef struct {
	u32 limit;		/* Expiration time (usec) */
	u32 increment;	/* Current expiration increment (usec) */
	u32 elapsed;		/* Current elapsed time (usec) */
	u32 tick;		/* O/S tick time (usec) */
} dhd_timeout_t;

typedef struct {
	uint event;
	const char *name;
} bcmevent_name_t;

#if defined(CONFIG_PM_SLEEP)
extern atomic_t dhd_mmc_suspend;
#define DHD_PM_RESUME_WAIT_INIT(a) DECLARE_WAIT_QUEUE_HEAD(a);
#define _DHD_PM_RESUME_WAIT(a, b) do { \
		int retry = 0; \
		while (atomic_read(&dhd_mmc_suspend) && retry++ != b) { \
			wait_event_timeout(a, false, HZ/100); \
		} \
	}	while (0)
#define DHD_PM_RESUME_WAIT(a)	_DHD_PM_RESUME_WAIT(a, 30)
#define DHD_PM_RESUME_WAIT_FOREVER(a)	_DHD_PM_RESUME_WAIT(a, ~0)
#define DHD_PM_RESUME_RETURN_ERROR(a)	\
	do { if (atomic_read(&dhd_mmc_suspend)) return a; } while (0)
#define DHD_PM_RESUME_RETURN	do { \
	if (atomic_read(&dhd_mmc_suspend)) \
		return; \
	} while (0)

#define DHD_SPINWAIT_SLEEP_INIT(a) DECLARE_WAIT_QUEUE_HEAD(a);
#define SPINWAIT_SLEEP(a, exp, us) do { \
		uint countdown = (us) + 9999; \
		while ((exp) && (countdown >= 10000)) { \
			wait_event_timeout(a, false, HZ/100); \
			countdown -= 10000; \
		} \
	} while (0)

#else

#define DHD_PM_RESUME_WAIT_INIT(a)
#define DHD_PM_RESUME_WAIT(a)
#define DHD_PM_RESUME_WAIT_FOREVER(a)
#define DHD_PM_RESUME_RETURN_ERROR(a)
#define DHD_PM_RESUME_RETURN

#define DHD_SPINWAIT_SLEEP_INIT(a)
#define SPINWAIT_SLEEP(a, exp, us)  do { \
		uint countdown = (us) + 9; \
		while ((exp) && (countdown >= 10)) { \
			udelay(10);  \
			countdown -= 10;  \
		} \
	} while (0)

#endif	/* defined(CONFIG_PM_SLEEP) */

/*
 * Insmod parameters for debug/test
 */

/* Watchdog timer interval */
extern uint dhd_watchdog_ms;

#if defined(DHD_DEBUG)
/* Console output poll interval */
extern uint dhd_console_ms;
#endif				/* defined(DHD_DEBUG) */

/* Use interrupts */
extern uint dhd_intr;

/* Use polling */
extern uint dhd_poll;

/* ARP offload agent mode */
extern uint dhd_arp_mode;

/* ARP offload enable */
extern uint dhd_arp_enable;

/* Pkt filte enable control */
extern uint dhd_pkt_filter_enable;

/*  Pkt filter init setup */
extern uint dhd_pkt_filter_init;

/* Pkt filter mode control */
extern uint dhd_master_mode;

/* Roaming mode control */
extern uint dhd_roam;

/* Roaming mode control */
extern uint dhd_radio_up;

/* Initial idletime ticks (may be -1 for immediate idle, 0 for no idle) */
extern int dhd_idletime;
#define DHD_IDLETIME_TICKS 1

/* SDIO Drive Strength */
extern uint dhd_sdiod_drive_strength;

/* Override to force tx queueing all the time */
extern uint dhd_force_tx_queueing;

#ifdef SDTEST
/* Echo packet generator (SDIO), pkts/s */
extern uint dhd_pktgen;

/* Echo packet len (0 => sawtooth, max 1800) */
extern uint dhd_pktgen_len;
#define MAX_PKTGEN_LEN 1800
#endif

extern char fw_path[MOD_PARAM_PATHLEN];
extern char nv_path[MOD_PARAM_PATHLEN];

extern u32 g_assert_type;
extern const bcmevent_name_t bcmevent_names[];
extern const int bcmevent_names_size;


static inline void MUTEX_LOCK_INIT(dhd_pub_t *dhdp)
{
}

static inline void MUTEX_LOCK(dhd_pub_t *dhdp)
{
}

static inline void MUTEX_UNLOCK(dhd_pub_t *dhdp)
{
}

static inline void MUTEX_LOCK_SOFTAP_SET_INIT(dhd_pub_t *dhdp)
{
}

static inline void MUTEX_LOCK_SOFTAP_SET(dhd_pub_t *dhdp)
{
}

static inline void MUTEX_UNLOCK_SOFTAP_SET(dhd_pub_t *dhdp)
{
}

static inline void MUTEX_LOCK_WL_SCAN_SET_INIT(void)
{
}

static inline void MUTEX_LOCK_WL_SCAN_SET(void)
{
}

static inline void MUTEX_UNLOCK_WL_SCAN_SET(void)
{
}

/*
 * Exported from dhd OS modules (dhd_linux/dhd_ndis)
 */

/* Indication from bus module regarding presence/insertion of dongle.
 * Return dhd_pub_t pointer, used as handle to OS module in later calls.
 * Returned structure should have bus and prot pointers filled in.
 * bus_hdrlen specifies required headroom for bus module header.
 */
extern dhd_pub_t *dhd_attach(struct dhd_bus *bus,
				uint bus_hdrlen);
extern int dhd_net_attach(dhd_pub_t *dhdp, int idx);

/* Indication from bus module regarding removal/absence of dongle */
extern void dhd_detach(dhd_pub_t *dhdp);

/* Indication from bus module to change flow-control state */
extern void dhd_txflowcontrol(dhd_pub_t *dhdp, int ifidx, bool on);

extern bool dhd_prec_enq(dhd_pub_t *dhdp, struct pktq *q,
			 struct sk_buff *pkt, int prec);

/* Receive frame for delivery to OS.  Callee disposes of rxp. */
extern void dhd_rx_frame(dhd_pub_t *dhdp, int ifidx,
			 struct sk_buff *rxp, int numpkt);

/* Return pointer to interface name */
extern char *dhd_ifname(dhd_pub_t *dhdp, int idx);

/* Request scheduling of the bus dpc */
extern void dhd_sched_dpc(dhd_pub_t *dhdp);

/* Notify tx completion */
extern void dhd_txcomplete(dhd_pub_t *dhdp, struct sk_buff *txp, bool success);

/* Query ioctl */
extern int dhdcdc_query_ioctl(dhd_pub_t *dhd, int ifidx, uint cmd, void *buf,
			      uint len);

/* OS independent layer functions */
extern int dhd_os_proto_block(dhd_pub_t *pub);
extern int dhd_os_proto_unblock(dhd_pub_t *pub);
extern int dhd_os_ioctl_resp_wait(dhd_pub_t *pub, uint *condition,
				  bool *pending);
extern int dhd_os_ioctl_resp_wake(dhd_pub_t *pub);
extern unsigned int dhd_os_get_ioctl_resp_timeout(void);
extern void dhd_os_set_ioctl_resp_timeout(unsigned int timeout_msec);
extern void *dhd_os_open_image(char *filename);
extern int dhd_os_get_image_block(char *buf, int len, void *image);
extern void dhd_os_close_image(void *image);
extern void dhd_os_wd_timer(void *bus, uint wdtick);
extern void dhd_os_sdlock(dhd_pub_t *pub);
extern void dhd_os_sdunlock(dhd_pub_t *pub);
extern void dhd_os_sdlock_txq(dhd_pub_t *pub);
extern void dhd_os_sdunlock_txq(dhd_pub_t *pub);
extern void dhd_os_sdlock_rxq(dhd_pub_t *pub);
extern void dhd_os_sdunlock_rxq(dhd_pub_t *pub);
extern void dhd_os_sdlock_sndup_rxq(dhd_pub_t *pub);
extern void dhd_customer_gpio_wlan_ctrl(int onoff);
extern int dhd_custom_get_mac_address(unsigned char *buf);
extern void dhd_os_sdunlock_sndup_rxq(dhd_pub_t *pub);
extern void dhd_os_sdlock_eventq(dhd_pub_t *pub);
extern void dhd_os_sdunlock_eventq(dhd_pub_t *pub);
#ifdef DHD_DEBUG
extern int write_to_file(dhd_pub_t *dhd, u8 *buf, int size);
#endif				/* DHD_DEBUG */
#if defined(OOB_INTR_ONLY)
extern int dhd_customer_oob_irq_map(unsigned long *irq_flags_ptr);
#endif				/* defined(OOB_INTR_ONLY) */
extern void dhd_os_sdtxlock(dhd_pub_t *pub);
extern void dhd_os_sdtxunlock(dhd_pub_t *pub);

int setScheduler(struct task_struct *p, int policy, struct sched_param *param);

extern void dhd_timeout_start(dhd_timeout_t *tmo, uint usec);
extern int dhd_timeout_expired(dhd_timeout_t *tmo);

extern int dhd_ifname2idx(struct dhd_info *dhd, char *name);
extern u8 *dhd_bssidx2bssid(dhd_pub_t *dhd, int idx);
extern int wl_host_event(struct dhd_info *dhd, int *idx, void *pktdata,
			 wl_event_msg_t *, void **data_ptr);

extern void dhd_common_init(void);

extern int dhd_add_if(struct dhd_info *dhd, int ifidx, void *handle,
		      char *name, u8 *mac_addr, u32 flags, u8 bssidx);
extern void dhd_del_if(struct dhd_info *dhd, int ifidx);

extern void dhd_vif_add(struct dhd_info *dhd, int ifidx, char *name);
extern void dhd_vif_del(struct dhd_info *dhd, int ifidx);

extern void dhd_event(struct dhd_info *dhd, char *evpkt, int evlen, int ifidx);
extern void dhd_vif_sendup(struct dhd_info *dhd, int ifidx, unsigned char * cp,
			   int len);

/* Send packet to dongle via data channel */
extern int dhd_sendpkt(dhd_pub_t *dhdp, int ifidx, struct sk_buff *pkt);

/* Send event to host */
extern void dhd_sendup_event(dhd_pub_t *dhdp, wl_event_msg_t *event,
			     void *data);
extern int dhd_bus_devreset(dhd_pub_t *dhdp, u8 flag);
extern uint dhd_bus_status(dhd_pub_t *dhdp);
extern int dhd_bus_start(dhd_pub_t *dhdp);

extern void dhd_wait_for_event(dhd_pub_t *dhd, bool * lockvar);
extern void dhd_wait_event_wakeup(dhd_pub_t *dhd);

#ifdef BCMDBG
#define ASSERT(exp) \
	  do { if (!(exp)) osl_assert(#exp, __FILE__, __LINE__); } while (0)
extern void osl_assert(char *exp, char *file, int line);
#else
#define ASSERT(exp)	do {} while (0)
#endif  /* defined(BCMDBG) */

/* Linux network driver ioctl encoding */
typedef struct dhd_ioctl {
	uint cmd;		/* common ioctl definition */
	void *buf;		/* pointer to user buffer */
	uint len;		/* length of user buffer */
	bool set;		/* get or set request (optional) */
	uint used;		/* bytes read or written (optional) */
	uint needed;		/* bytes needed (optional) */
	uint driver;		/* to identify target driver */
} dhd_ioctl_t;

/* per-driver magic numbers */
#define DHD_IOCTL_MAGIC		0x00444944

/* bump this number if you change the ioctl interface */
#define DHD_IOCTL_VERSION	1

#define	DHD_IOCTL_MAXLEN	8192	/* max length ioctl buffer required */
#define	DHD_IOCTL_SMLEN	256	/* "small" length ioctl buffer required */

/* common ioctl definitions */
#define DHD_GET_MAGIC				0
#define DHD_GET_VERSION				1
#define DHD_GET_VAR				2
#define DHD_SET_VAR				3

/* message levels */
#define DHD_ERROR_VAL	0x0001
#define DHD_TRACE_VAL	0x0002
#define DHD_INFO_VAL	0x0004
#define DHD_DATA_VAL	0x0008
#define DHD_CTL_VAL	0x0010
#define DHD_TIMER_VAL	0x0020
#define DHD_HDRS_VAL	0x0040
#define DHD_BYTES_VAL	0x0080
#define DHD_INTR_VAL	0x0100
#define DHD_LOG_VAL	0x0200
#define DHD_GLOM_VAL	0x0400
#define DHD_EVENT_VAL	0x0800
#define DHD_BTA_VAL	0x1000
#define DHD_ISCAN_VAL 0x2000

#ifdef SDTEST
/* For pktgen iovar */
typedef struct dhd_pktgen {
	uint version;		/* To allow structure change tracking */
	uint freq;		/* Max ticks between tx/rx attempts */
	uint count;		/* Test packets to send/rcv each attempt */
	uint print;		/* Print counts every <print> attempts */
	uint total;		/* Total packets (or bursts) */
	uint minlen;		/* Minimum length of packets to send */
	uint maxlen;		/* Maximum length of packets to send */
	uint numsent;		/* Count of test packets sent */
	uint numrcvd;		/* Count of test packets received */
	uint numfail;		/* Count of test send failures */
	uint mode;		/* Test mode (type of test packets) */
	uint stop;		/* Stop after this many tx failures */
} dhd_pktgen_t;

/* Version in case structure changes */
#define DHD_PKTGEN_VERSION 2

/* Type of test packets to use */
#define DHD_PKTGEN_ECHO		1	/* Send echo requests */
#define DHD_PKTGEN_SEND		2	/* Send discard packets */
#define DHD_PKTGEN_RXBURST	3	/* Request dongle send N packets */
#define DHD_PKTGEN_RECV		4	/* Continuous rx from continuous
					 tx dongle */
#endif				/* SDTEST */

/* Enter idle immediately (no timeout) */
#define DHD_IDLE_IMMEDIATE	(-1)

/* Values for idleclock iovar: other values are the sd_divisor to use
	 when idle */
#define DHD_IDLE_ACTIVE	0	/* Do not request any SD clock change
				 when idle */
#define DHD_IDLE_STOP   (-1)	/* Request SD clock be stopped
				 (and use SD1 mode) */

#endif				/* _dhd_h_ */
