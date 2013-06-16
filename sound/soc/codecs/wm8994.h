<<<<<<< HEAD
/*
 * wm8994.h  --  WM8994 Soc Audio driver
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef _WM8994_H
#define _WM8994_H

#include <sound/soc.h>


/* Sources for AIF1/2 SYSCLK - use with set_dai_sysclk() */
#define WM8994_SYSCLK_MCLK1 1
#define WM8994_SYSCLK_MCLK2 2
#define WM8994_SYSCLK_FLL1  3
#define WM8994_SYSCLK_FLL2  4

#define WM8994_FLL1 1
#define WM8994_FLL2 2

/* Added belows codes by Samsung Electronics.*/

#include "wm8994_def.h"

#define WM8994_SYSCLK_MCLK     1
#define WM8994_SYSCLK_FLL      2

#define AUDIO_COMMON_DEBUG  0 

#define DEACTIVE            0x00
#define PLAYBACK_ACTIVE     0x01
#define CAPTURE_ACTIVE      0x02
#define CALL_ACTIVE         0x04
#define FMRADIO_ACTIVE      0x08

#define PCM_STREAM_DEACTIVE 0x00
#define PCM_STREAM_PLAYBACK 0x01
#define PCM_STREAM_CAPTURE  0x02

#define CMD_FMR_INPUT_DEACTIVE          0 // Codec Input PGA off for reducing white noise.
#define CMD_FMR_INPUT_ACTIVE            1 // Codec Input PGA on
#define CMD_FMR_FLAG_CLEAR              2 // Radio flag clear for shutdown - to reduce pop up noise.
#define CMD_FMR_END                     3 // Codec off in FM radio mode - to reduce pop up noise.
#define CMD_RECOGNITION_DEACTIVE        4 // Distingush recognition gain. To use default MIC gain.
#define CMD_RECOGNITION_ACTIVE          5 // Distingush recognition gain. To use MIC gain for recognition.
#define CMD_CALL_FLAG_CLEAR             6 // Call flag clear for shutdown - to reduce pop up noise.
#define CMD_CALL_END                    7 // Codec off in call mode - to reduce pop up noise.

#define HPAMP_OFF       0x00
#define HPAMP_PLAYBACK  0x01
#define HPAMP_CALL      0x02
#define HPAMP_FMR       0x04
#define HPAMP_CH_NORMAL 0x08

#define CODEC_TURN_OFF	0x01
=======
/*
 * wm8994.h  --  WM8994 Soc Audio driver
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef _WM8994_H
#define _WM8994_H

#include <sound/soc.h>
#include <linux/firmware.h>
#include <linux/completion.h>

#include "wm_hubs.h"

/* Sources for AIF1/2 SYSCLK - use with set_dai_sysclk() */
#define WM8994_SYSCLK_MCLK1 1
#define WM8994_SYSCLK_MCLK2 2
#define WM8994_SYSCLK_FLL1  3
#define WM8994_SYSCLK_FLL2  4

/* OPCLK is also configured with set_dai_sysclk, specify division*10 as rate. */
#define WM8994_SYSCLK_OPCLK 5

#define WM8994_FLL1 1
#define WM8994_FLL2 2

#define WM8994_FLL_SRC_MCLK1  1
#define WM8994_FLL_SRC_MCLK2  2
#define WM8994_FLL_SRC_LRCLK  3
#define WM8994_FLL_SRC_BCLK   4

typedef void (*wm8958_micdet_cb)(u16 status, void *data);

int wm8994_mic_detect(struct snd_soc_codec *codec, struct snd_soc_jack *jack,
		      int micbias, int det, int shrt);
int wm8958_mic_detect(struct snd_soc_codec *codec, struct snd_soc_jack *jack,
		      wm8958_micdet_cb cb, void *cb_data);

#define WM8994_CACHE_SIZE 1570

struct wm8994_access_mask {
	unsigned short readable;   /* Mask of readable bits */
	unsigned short writable;   /* Mask of writable bits */
};

extern const struct wm8994_access_mask wm8994_access_masks[WM8994_CACHE_SIZE];
extern const u16 wm8994_reg_defaults[WM8994_CACHE_SIZE];

int wm8958_aif_ev(struct snd_soc_dapm_widget *w,
		  struct snd_kcontrol *kcontrol, int event);

void wm8958_dsp2_init(struct snd_soc_codec *codec);

struct wm8994_micdet {
	struct snd_soc_jack *jack;
	int det;
	int shrt;
};
>>>>>>> v3.1

/*
 * Definitions of enum type
 */
enum playback_path            { PLAYBACK_OFF, RCV, SPK, HP, HP_NO_MIC, BT, SPK_HP,RING_SPK, RING_HP, RING_NO_MIC, RING_SPK_HP, EXTRA_DOCK_SPEAKER, TV_OUT, HDMI_TV_OUT, HDMI_SPK, HDMI_DUAL };
enum mic_path		       { MAIN, SUB, BT_REC, MIC_OFF };
enum fmradio_path          { FMR_OFF, FMR_SPK, FMR_HP, FMR_SPK_MIX, FMR_HP_MIX, FMR_DUAL_MIX };
enum fmradio_mix_path	   { FMR_MIX_OFF, FMR_MIX_HP, FMR_MIX_SPK, FMR_MIX_DUAL };
enum power_state	       { CODEC_OFF, CODEC_ON };
enum recognition	       { REC_OFF, REC_ON };
enum state                 { OFF, ON };
enum voice_record_path     { CALL_RECORDING_OFF, CALL_RECORDING_MAIN, CALL_RECORDING_SUB};
enum factory_test          { SEC_NORMAL, SEC_TEST_HWCODEC , SEC_TEST_15MODE, SEC_TEST_PBA_LOOPBACK, SEC_TEST_PBA_DUAL_SPK, SEC_TEST_HQRL_LOOPBACK};
enum call_recording_channel {CH_OFF, CH_UPLINK, CH_DOWNLINK, CH_UDLINK};


typedef void (*select_route)(struct snd_soc_codec *);
typedef void (*select_mic_route)(struct snd_soc_codec *);

struct wm8994_setup_data {
	int i2c_bus;
	unsigned short i2c_address;
};

struct wm8994_priv {
	struct snd_soc_codec *codec;
<<<<<<< HEAD
	int master;
	int sysclk_source;
	unsigned int mclk_rate;
	unsigned int sysclk_rate;
	unsigned int fs;
	unsigned int bclk;
	unsigned int codec_state;
	unsigned int  stream_state;
	enum playback_path cur_path;
	enum mic_path rec_path;
	enum fmradio_path fmradio_path;
	enum fmradio_mix_path fmr_mix_path;
	enum power_state power_state;
	enum recognition recognition_active;		// for control gain to voice recognition.
	enum state ringtone_active;
	enum voice_record_path call_record_path;
	enum call_recording_channel call_record_ch;
	select_route *universal_playback_path;
	select_route *universal_voicecall_path;
	select_mic_route *universal_mic_path;
	int testmode_config_flag;	// for testmode.
	unsigned int hw_version;
=======
	int sysclk[2];
	int sysclk_rate[2];
	int mclk[2];
	int aifclk[2];
	struct wm8994_fll_config fll[2], fll_suspend[2];
	struct completion fll_locked[2];
	bool fll_locked_irq;

	int dac_rates[2];
	int lrclk_shared[2];

	int mbc_ena[3];
	int hpf1_ena[3];
	int hpf2_ena[3];
	int vss_ena[3];
	int enh_eq_ena[3];

	/* Platform dependant DRC configuration */
	const char **drc_texts;
	int drc_cfg[WM8994_NUM_DRC];
	struct soc_enum drc_enum;

	/* Platform dependant ReTune mobile configuration */
	int num_retune_mobile_texts;
	const char **retune_mobile_texts;
	int retune_mobile_cfg[WM8994_NUM_EQ];
	struct soc_enum retune_mobile_enum;

	/* Platform dependant MBC configuration */
	int mbc_cfg;
	const char **mbc_texts;
	struct soc_enum mbc_enum;

	/* Platform dependant VSS configuration */
	int vss_cfg;
	const char **vss_texts;
	struct soc_enum vss_enum;

	/* Platform dependant VSS HPF configuration */
	int vss_hpf_cfg;
	const char **vss_hpf_texts;
	struct soc_enum vss_hpf_enum;

	/* Platform dependant enhanced EQ configuration */
	int enh_eq_cfg;
	const char **enh_eq_texts;
	struct soc_enum enh_eq_enum;

	struct wm8994_micdet micdet[2];

	wm8958_micdet_cb jack_cb;
	void *jack_cb_data;
	int micdet_irq;

	int revision;
	struct wm8994_pdata *pdata;

	unsigned int aif1clk_enable:1;
	unsigned int aif2clk_enable:1;

	unsigned int aif1clk_disable:1;
	unsigned int aif2clk_disable:1;

	int dsp_active;
	const struct firmware *cur_fw;
	const struct firmware *mbc;
	const struct firmware *mbc_vss;
	const struct firmware *enh_eq;
>>>>>>> v3.1
};

#if AUDIO_COMMON_DEBUG
#define DEBUG_LOG(format, ...)\
	printk(KERN_INFO "[ "SUBJECT " (%s,%d) ] " format "\n", \
			__func__, __LINE__, ## __VA_ARGS__);
#else
#define DEBUG_LOG(format, ...)
#endif

#define DEBUG_LOG_ERR(format, ...)\
	printk(KERN_ERR "[ "SUBJECT " (%s,%d) ] " format "\n", \
			__func__, __LINE__, ## __VA_ARGS__);

/* Definitions of function prototype. */
unsigned int wm8994_read(struct snd_soc_codec *codec,unsigned int reg);
int wm8994_write(struct snd_soc_codec *codec, unsigned int reg, unsigned int value);
int audio_init(void);
int audio_power(int en);

void wm8994_set_off(struct snd_soc_codec *codec);
void wm8994_disable_playback_path(struct snd_soc_codec *codec);
void wm8994_disable_fmradio_path(struct snd_soc_codec *codec);
void wm8994_disable_rec_path(struct snd_soc_codec *codec);
void  wm8994_record_main_mic( struct snd_soc_codec *codec);
void wm8994_record_headset_mic( struct snd_soc_codec *codec);
void wm8994_record_bluetooth(struct snd_soc_codec *codec);
void wm8994_set_playback_receiver(struct snd_soc_codec *codec);
void wm8994_set_playback_headset(struct snd_soc_codec *codec);
void wm8994_set_playback_speaker(struct snd_soc_codec *codec);
void wm8994_set_playback_speaker_headset(struct snd_soc_codec *codec);
void wm8994_set_playback_bluetooth(struct snd_soc_codec *codec);
void wm8994_set_playback_extra_dock_speaker(struct snd_soc_codec *codec);
void wm8994_set_playback_hdmi_tvout(struct snd_soc_codec *codec);
void wm8994_set_playback_speaker_hdmitvout(struct snd_soc_codec *codec);
void wm8994_set_playback_speakerheadset_hdmitvout(struct snd_soc_codec *codec);
void wm8994_set_voicecall_common_setting(struct snd_soc_codec *codec);
void wm8994_set_voicecall_receiver(struct snd_soc_codec *codec);
void wm8994_set_voicecall_headphone(struct snd_soc_codec *codec);
void wm8994_set_voicecall_headset(struct snd_soc_codec *codec);
void wm8994_set_voicecall_speaker(struct snd_soc_codec *codec);
void wm8994_set_voicecall_bluetooth(struct snd_soc_codec *codec);
void wm8994_set_voicecall_record(struct snd_soc_codec *codec, int path_num);
void wm8994_call_recording_change_path(struct snd_soc_codec *codec);
void wm8994_set_voicecall_record_off(struct snd_soc_codec *codec);
void wm8994_set_fmradio_common(struct snd_soc_codec *codec, int onoff);
void wm8994_set_fmradio_headset(struct snd_soc_codec *codec);
void wm8994_set_fmradio_speaker(struct snd_soc_codec *codec);
void wm8994_set_fmradio_headset_mix(struct snd_soc_codec *codec);
void wm8994_set_fmradio_speaker_mix(struct snd_soc_codec *codec);
void wm8994_set_fmradio_speaker_headset_mix(struct snd_soc_codec *codec);
#if defined WM8994_REGISTER_DUMP
void wm8994_register_dump(struct snd_soc_codec *codec);
#endif
#endif

void audio_ctrl_earmic_bias_gpio(int enable);
void audio_ctrl_mic_bias_gpio(int enable);

int get_audio_power_status(void);

