#define FRAME_TYPE_MANAGEMENT 0
#define FRAME_TYPE_CONTROL
#define FRAME_TYPE_DATA 2
# Define FRAME_SUBTYPE_PROBE_REQUEST 0x04
#define FRAME_SUBTYPE_PROBE_RESPONSE 0x05
#define FRAME_SUBTYPE_BEACON 0x08
#define FRAME_SUBTYPE_AUTH 0x0b
# Define FRAME_SUBTYPE_DEAUTH 0x0c
#define FRAME_SUBTYPE_DATA 0x14
Typedef struct framectrl_80211
{
    // buf [0]
    U8 Protocol: 2;
    U8 Type: 2;
    U8 Subtype: 4;
    // buf [1]
    U8 ToDS: 1;
    U8 FromDS: 1;
    U8 MoreFlag: 1;
    U8 Retry: 1;
    U8 PwrMgmt: 1;
    U8 MoreData: 1;
    U8 Protectedframe: 1;
    U8 Order: 1;
} Framectrl_80211, * lpframectrl_80211;

Typedef struct probe_request_80211
{
Struct framectrl_80211 framectrl;
Uint16 duration;
Uint8 rdaddr [6];
Tsintr [6];
Uint8 bssid [6];
Uint16 number;
} Probe_request, * pprobe_request;

Typedef struct tagged_parameter
{
/ * SSID parameter * /
Uint8 tag_number;
Uint8 tag_length;
} Tagged_parameter, * ptagged_parameter;

Struct RxControl {
    Signed rssi: 8; // said the packet's signal strength
    Unsigned rate: 4;
    Unsigned is_group: 1;
    Unsigned: 1;
    Unsigned sig_mode: 2; // 11n that the packet is a packet, 0 said non-11n, non-0 said 11n
    Unsigned legacy_length: 12; // If it is not 11n, it represents the length of the packet
    Unsigned damatch0: 1;
    Unsigned damatch1: 1;
    Unsigned bssidmatch0: 1;
    Unsigned bssidmatch1: 1;
    Unsigned MCS: 7; // If it is 11n of the packet, which represents the modulation coding sequence of packets, valid values: 0-76
    Unsigned CWB: 1; // If it is 11n of the packet, it indicates whether the HT40 package
    Unsigned HT_length: 16; // If it is 11n of the package, which said the length of the package
    Unsigned Smoothing: 1;
    Unsigned Not_Sounding: 1;
    Unsigned: 1;
    Unsigned Aggregation: 1;
    Unsigned STBC: 2;
    Unsigned FEC_CODING: 1; // If it is 11n packet, it indicates whether the LDPC package
    Unsigned SGI: 1;
    Unsigned rxend_state: 8;
    Unsigned ampdu_cnt: 8;
    Unsigned channel: 4; // said the packet where the channel
    Unsigned: 12;
};

Struct sniffer_buf {
Struct RxControl rx_ctrl;
U8 buf [48]; // contains the ieee80211 header
U16 cnt; / / the number of packets
U16 len [1]; // The length of the packet
};
