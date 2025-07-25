/* Generated from estonian.sbl by Snowball 3.0.1 - https://snowballstem.org/ */

#include "../runtime/header.h"

#ifdef __cplusplus
extern "C" {
#endif
extern int estonian_UTF_8_stem(struct SN_env * z);
#ifdef __cplusplus
}
#endif
static int r_nu(struct SN_env * z);
static int r_verb(struct SN_env * z);
static int r_verb_exceptions(struct SN_env * z);
static int r_substantive(struct SN_env * z);
static int r_degrees(struct SN_env * z);
static int r_i_plural(struct SN_env * z);
static int r_undouble_kpt(struct SN_env * z);
static int r_plural_three_first_cases(struct SN_env * z);
static int r_emphasis(struct SN_env * z);
static int r_case_ending(struct SN_env * z);
static int r_special_noun_endings(struct SN_env * z);
static int r_LONGV(struct SN_env * z);
static int r_mark_regions(struct SN_env * z);
#ifdef __cplusplus
extern "C" {
#endif


extern struct SN_env * estonian_UTF_8_create_env(void);
extern void estonian_UTF_8_close_env(struct SN_env * z);


#ifdef __cplusplus
}
#endif
static const symbol s_0_0[2] = { 'g', 'i' };
static const symbol s_0_1[2] = { 'k', 'i' };
static const struct among a_0[2] = {
{ 2, s_0_0, 0, 1, 0},
{ 2, s_0_1, 0, 2, 0}
};

static const symbol s_1_0[2] = { 'd', 'a' };
static const symbol s_1_1[4] = { 'm', 'a', 't', 'a' };
static const symbol s_1_2[1] = { 'b' };
static const symbol s_1_3[4] = { 'k', 's', 'i', 'd' };
static const symbol s_1_4[6] = { 'n', 'u', 'k', 's', 'i', 'd' };
static const symbol s_1_5[2] = { 'm', 'e' };
static const symbol s_1_6[4] = { 's', 'i', 'm', 'e' };
static const symbol s_1_7[5] = { 'k', 's', 'i', 'm', 'e' };
static const symbol s_1_8[7] = { 'n', 'u', 'k', 's', 'i', 'm', 'e' };
static const symbol s_1_9[4] = { 'a', 'k', 's', 'e' };
static const symbol s_1_10[5] = { 'd', 'a', 'k', 's', 'e' };
static const symbol s_1_11[5] = { 't', 'a', 'k', 's', 'e' };
static const symbol s_1_12[4] = { 's', 'i', 't', 'e' };
static const symbol s_1_13[5] = { 'k', 's', 'i', 't', 'e' };
static const symbol s_1_14[7] = { 'n', 'u', 'k', 's', 'i', 't', 'e' };
static const symbol s_1_15[1] = { 'n' };
static const symbol s_1_16[3] = { 's', 'i', 'n' };
static const symbol s_1_17[4] = { 'k', 's', 'i', 'n' };
static const symbol s_1_18[6] = { 'n', 'u', 'k', 's', 'i', 'n' };
static const symbol s_1_19[4] = { 'd', 'a', 'k', 's' };
static const symbol s_1_20[4] = { 't', 'a', 'k', 's' };
static const struct among a_1[21] = {
{ 2, s_1_0, 0, 3, 0},
{ 4, s_1_1, 0, 1, 0},
{ 1, s_1_2, 0, 3, 0},
{ 4, s_1_3, 0, 1, 0},
{ 6, s_1_4, -1, 1, 0},
{ 2, s_1_5, 0, 3, 0},
{ 4, s_1_6, -1, 1, 0},
{ 5, s_1_7, -1, 1, 0},
{ 7, s_1_8, -1, 1, 0},
{ 4, s_1_9, 0, 2, 0},
{ 5, s_1_10, -1, 1, 0},
{ 5, s_1_11, -2, 1, 0},
{ 4, s_1_12, 0, 1, 0},
{ 5, s_1_13, -1, 1, 0},
{ 7, s_1_14, -1, 1, 0},
{ 1, s_1_15, 0, 3, 0},
{ 3, s_1_16, -1, 1, 0},
{ 4, s_1_17, -1, 1, 0},
{ 6, s_1_18, -1, 1, 0},
{ 4, s_1_19, 0, 1, 0},
{ 4, s_1_20, 0, 1, 0}
};

static const symbol s_2_0[2] = { 'a', 'a' };
static const symbol s_2_1[2] = { 'e', 'e' };
static const symbol s_2_2[2] = { 'i', 'i' };
static const symbol s_2_3[2] = { 'o', 'o' };
static const symbol s_2_4[2] = { 'u', 'u' };
static const symbol s_2_5[4] = { 0xC3, 0xA4, 0xC3, 0xA4 };
static const symbol s_2_6[4] = { 0xC3, 0xB5, 0xC3, 0xB5 };
static const symbol s_2_7[4] = { 0xC3, 0xB6, 0xC3, 0xB6 };
static const symbol s_2_8[4] = { 0xC3, 0xBC, 0xC3, 0xBC };
static const struct among a_2[9] = {
{ 2, s_2_0, 0, -1, 0},
{ 2, s_2_1, 0, -1, 0},
{ 2, s_2_2, 0, -1, 0},
{ 2, s_2_3, 0, -1, 0},
{ 2, s_2_4, 0, -1, 0},
{ 4, s_2_5, 0, -1, 0},
{ 4, s_2_6, 0, -1, 0},
{ 4, s_2_7, 0, -1, 0},
{ 4, s_2_8, 0, -1, 0}
};

static const symbol s_3_0[1] = { 'i' };
static const struct among a_3[1] = {
{ 1, s_3_0, 0, 1, 0}
};

static const symbol s_4_0[4] = { 'l', 'a', 'n', 'e' };
static const symbol s_4_1[4] = { 'l', 'i', 'n', 'e' };
static const symbol s_4_2[4] = { 'm', 'i', 'n', 'e' };
static const symbol s_4_3[5] = { 'l', 'a', 's', 's', 'e' };
static const symbol s_4_4[5] = { 'l', 'i', 's', 's', 'e' };
static const symbol s_4_5[5] = { 'm', 'i', 's', 's', 'e' };
static const symbol s_4_6[4] = { 'l', 'a', 's', 'i' };
static const symbol s_4_7[4] = { 'l', 'i', 's', 'i' };
static const symbol s_4_8[4] = { 'm', 'i', 's', 'i' };
static const symbol s_4_9[4] = { 'l', 'a', 's', 't' };
static const symbol s_4_10[4] = { 'l', 'i', 's', 't' };
static const symbol s_4_11[4] = { 'm', 'i', 's', 't' };
static const struct among a_4[12] = {
{ 4, s_4_0, 0, 1, 0},
{ 4, s_4_1, 0, 3, 0},
{ 4, s_4_2, 0, 2, 0},
{ 5, s_4_3, 0, 1, 0},
{ 5, s_4_4, 0, 3, 0},
{ 5, s_4_5, 0, 2, 0},
{ 4, s_4_6, 0, 1, 0},
{ 4, s_4_7, 0, 3, 0},
{ 4, s_4_8, 0, 2, 0},
{ 4, s_4_9, 0, 1, 0},
{ 4, s_4_10, 0, 3, 0},
{ 4, s_4_11, 0, 2, 0}
};

static const symbol s_5_0[2] = { 'g', 'a' };
static const symbol s_5_1[2] = { 't', 'a' };
static const symbol s_5_2[2] = { 'l', 'e' };
static const symbol s_5_3[3] = { 's', 's', 'e' };
static const symbol s_5_4[1] = { 'l' };
static const symbol s_5_5[1] = { 's' };
static const symbol s_5_6[2] = { 'k', 's' };
static const symbol s_5_7[1] = { 't' };
static const symbol s_5_8[2] = { 'l', 't' };
static const symbol s_5_9[2] = { 's', 't' };
static const struct among a_5[10] = {
{ 2, s_5_0, 0, 1, 0},
{ 2, s_5_1, 0, 1, 0},
{ 2, s_5_2, 0, 1, 0},
{ 3, s_5_3, 0, 1, 0},
{ 1, s_5_4, 0, 1, 0},
{ 1, s_5_5, 0, 1, 0},
{ 2, s_5_6, -1, 1, 0},
{ 1, s_5_7, 0, 2, 0},
{ 2, s_5_8, -1, 1, 0},
{ 2, s_5_9, -2, 1, 0}
};

static const symbol s_6_1[3] = { 'l', 'a', 's' };
static const symbol s_6_2[3] = { 'l', 'i', 's' };
static const symbol s_6_3[3] = { 'm', 'i', 's' };
static const symbol s_6_4[1] = { 't' };
static const struct among a_6[5] = {
{ 0, 0, 0, 2, 0},
{ 3, s_6_1, -1, 1, 0},
{ 3, s_6_2, -2, 1, 0},
{ 3, s_6_3, -3, 1, 0},
{ 1, s_6_4, -4, -1, 0}
};

static const symbol s_7_0[1] = { 'd' };
static const symbol s_7_1[3] = { 's', 'i', 'd' };
static const symbol s_7_2[2] = { 'd', 'e' };
static const symbol s_7_3[6] = { 'i', 'k', 'k', 'u', 'd', 'e' };
static const symbol s_7_4[3] = { 'i', 'k', 'e' };
static const symbol s_7_5[4] = { 'i', 'k', 'k', 'e' };
static const symbol s_7_6[2] = { 't', 'e' };
static const struct among a_7[7] = {
{ 1, s_7_0, 0, 4, 0},
{ 3, s_7_1, -1, 2, 0},
{ 2, s_7_2, 0, 4, 0},
{ 6, s_7_3, -1, 1, 0},
{ 3, s_7_4, 0, 1, 0},
{ 4, s_7_5, 0, 1, 0},
{ 2, s_7_6, 0, 3, 0}
};

static const symbol s_8_0[2] = { 'v', 'a' };
static const symbol s_8_1[2] = { 'd', 'u' };
static const symbol s_8_2[2] = { 'n', 'u' };
static const symbol s_8_3[2] = { 't', 'u' };
static const struct among a_8[4] = {
{ 2, s_8_0, 0, -1, 0},
{ 2, s_8_1, 0, -1, 0},
{ 2, s_8_2, 0, -1, 0},
{ 2, s_8_3, 0, -1, 0}
};

static const symbol s_9_0[2] = { 'k', 'k' };
static const symbol s_9_1[2] = { 'p', 'p' };
static const symbol s_9_2[2] = { 't', 't' };
static const struct among a_9[3] = {
{ 2, s_9_0, 0, 1, 0},
{ 2, s_9_1, 0, 2, 0},
{ 2, s_9_2, 0, 3, 0}
};

static const symbol s_10_0[2] = { 'm', 'a' };
static const symbol s_10_1[3] = { 'm', 'a', 'i' };
static const symbol s_10_2[1] = { 'm' };
static const struct among a_10[3] = {
{ 2, s_10_0, 0, 2, 0},
{ 3, s_10_1, 0, 1, 0},
{ 1, s_10_2, 0, 1, 0}
};

static const symbol s_11_0[4] = { 'j', 'o', 'o', 'b' };
static const symbol s_11_1[4] = { 'j', 'o', 'o', 'd' };
static const symbol s_11_2[8] = { 'j', 'o', 'o', 'd', 'a', 'k', 's', 'e' };
static const symbol s_11_3[5] = { 'j', 'o', 'o', 'm', 'a' };
static const symbol s_11_4[7] = { 'j', 'o', 'o', 'm', 'a', 't', 'a' };
static const symbol s_11_5[5] = { 'j', 'o', 'o', 'm', 'e' };
static const symbol s_11_6[4] = { 'j', 'o', 'o', 'n' };
static const symbol s_11_7[5] = { 'j', 'o', 'o', 't', 'e' };
static const symbol s_11_8[6] = { 'j', 'o', 'o', 'v', 'a', 'd' };
static const symbol s_11_9[4] = { 'j', 'u', 'u', 'a' };
static const symbol s_11_10[7] = { 'j', 'u', 'u', 'a', 'k', 's', 'e' };
static const symbol s_11_11[4] = { 'j', 0xC3, 0xA4, 'i' };
static const symbol s_11_12[5] = { 'j', 0xC3, 0xA4, 'i', 'd' };
static const symbol s_11_13[6] = { 'j', 0xC3, 0xA4, 'i', 'm', 'e' };
static const symbol s_11_14[5] = { 'j', 0xC3, 0xA4, 'i', 'n' };
static const symbol s_11_15[6] = { 'j', 0xC3, 0xA4, 'i', 't', 'e' };
static const symbol s_11_16[6] = { 'j', 0xC3, 0xA4, 0xC3, 0xA4, 'b' };
static const symbol s_11_17[6] = { 'j', 0xC3, 0xA4, 0xC3, 0xA4, 'd' };
static const symbol s_11_18[7] = { 'j', 0xC3, 0xA4, 0xC3, 0xA4, 'd', 'a' };
static const symbol s_11_19[10] = { 'j', 0xC3, 0xA4, 0xC3, 0xA4, 'd', 'a', 'k', 's', 'e' };
static const symbol s_11_20[7] = { 'j', 0xC3, 0xA4, 0xC3, 0xA4, 'd', 'i' };
static const symbol s_11_21[7] = { 'j', 0xC3, 0xA4, 0xC3, 0xA4, 'k', 's' };
static const symbol s_11_22[9] = { 'j', 0xC3, 0xA4, 0xC3, 0xA4, 'k', 's', 'i', 'd' };
static const symbol s_11_23[10] = { 'j', 0xC3, 0xA4, 0xC3, 0xA4, 'k', 's', 'i', 'm', 'e' };
static const symbol s_11_24[9] = { 'j', 0xC3, 0xA4, 0xC3, 0xA4, 'k', 's', 'i', 'n' };
static const symbol s_11_25[10] = { 'j', 0xC3, 0xA4, 0xC3, 0xA4, 'k', 's', 'i', 't', 'e' };
static const symbol s_11_26[7] = { 'j', 0xC3, 0xA4, 0xC3, 0xA4, 'm', 'a' };
static const symbol s_11_27[9] = { 'j', 0xC3, 0xA4, 0xC3, 0xA4, 'm', 'a', 't', 'a' };
static const symbol s_11_28[7] = { 'j', 0xC3, 0xA4, 0xC3, 0xA4, 'm', 'e' };
static const symbol s_11_29[6] = { 'j', 0xC3, 0xA4, 0xC3, 0xA4, 'n' };
static const symbol s_11_30[7] = { 'j', 0xC3, 0xA4, 0xC3, 0xA4, 't', 'e' };
static const symbol s_11_31[8] = { 'j', 0xC3, 0xA4, 0xC3, 0xA4, 'v', 'a', 'd' };
static const symbol s_11_32[4] = { 'j', 0xC3, 0xB5, 'i' };
static const symbol s_11_33[5] = { 'j', 0xC3, 0xB5, 'i', 'd' };
static const symbol s_11_34[6] = { 'j', 0xC3, 0xB5, 'i', 'm', 'e' };
static const symbol s_11_35[5] = { 'j', 0xC3, 0xB5, 'i', 'n' };
static const symbol s_11_36[6] = { 'j', 0xC3, 0xB5, 'i', 't', 'e' };
static const symbol s_11_37[4] = { 'k', 'e', 'e', 'b' };
static const symbol s_11_38[4] = { 'k', 'e', 'e', 'd' };
static const symbol s_11_39[8] = { 'k', 'e', 'e', 'd', 'a', 'k', 's', 'e' };
static const symbol s_11_40[5] = { 'k', 'e', 'e', 'k', 's' };
static const symbol s_11_41[7] = { 'k', 'e', 'e', 'k', 's', 'i', 'd' };
static const symbol s_11_42[8] = { 'k', 'e', 'e', 'k', 's', 'i', 'm', 'e' };
static const symbol s_11_43[7] = { 'k', 'e', 'e', 'k', 's', 'i', 'n' };
static const symbol s_11_44[8] = { 'k', 'e', 'e', 'k', 's', 'i', 't', 'e' };
static const symbol s_11_45[5] = { 'k', 'e', 'e', 'm', 'a' };
static const symbol s_11_46[7] = { 'k', 'e', 'e', 'm', 'a', 't', 'a' };
static const symbol s_11_47[5] = { 'k', 'e', 'e', 'm', 'e' };
static const symbol s_11_48[4] = { 'k', 'e', 'e', 'n' };
static const symbol s_11_49[4] = { 'k', 'e', 'e', 's' };
static const symbol s_11_50[5] = { 'k', 'e', 'e', 't', 'a' };
static const symbol s_11_51[5] = { 'k', 'e', 'e', 't', 'e' };
static const symbol s_11_52[6] = { 'k', 'e', 'e', 'v', 'a', 'd' };
static const symbol s_11_53[5] = { 'k', 0xC3, 0xA4, 'i', 'a' };
static const symbol s_11_54[8] = { 'k', 0xC3, 0xA4, 'i', 'a', 'k', 's', 'e' };
static const symbol s_11_55[5] = { 'k', 0xC3, 0xA4, 'i', 'b' };
static const symbol s_11_56[5] = { 'k', 0xC3, 0xA4, 'i', 'd' };
static const symbol s_11_57[6] = { 'k', 0xC3, 0xA4, 'i', 'd', 'i' };
static const symbol s_11_58[6] = { 'k', 0xC3, 0xA4, 'i', 'k', 's' };
static const symbol s_11_59[8] = { 'k', 0xC3, 0xA4, 'i', 'k', 's', 'i', 'd' };
static const symbol s_11_60[9] = { 'k', 0xC3, 0xA4, 'i', 'k', 's', 'i', 'm', 'e' };
static const symbol s_11_61[8] = { 'k', 0xC3, 0xA4, 'i', 'k', 's', 'i', 'n' };
static const symbol s_11_62[9] = { 'k', 0xC3, 0xA4, 'i', 'k', 's', 'i', 't', 'e' };
static const symbol s_11_63[6] = { 'k', 0xC3, 0xA4, 'i', 'm', 'a' };
static const symbol s_11_64[8] = { 'k', 0xC3, 0xA4, 'i', 'm', 'a', 't', 'a' };
static const symbol s_11_65[6] = { 'k', 0xC3, 0xA4, 'i', 'm', 'e' };
static const symbol s_11_66[5] = { 'k', 0xC3, 0xA4, 'i', 'n' };
static const symbol s_11_67[5] = { 'k', 0xC3, 0xA4, 'i', 's' };
static const symbol s_11_68[6] = { 'k', 0xC3, 0xA4, 'i', 't', 'e' };
static const symbol s_11_69[7] = { 'k', 0xC3, 0xA4, 'i', 'v', 'a', 'd' };
static const symbol s_11_70[4] = { 'l', 'a', 'o', 'b' };
static const symbol s_11_71[4] = { 'l', 'a', 'o', 'd' };
static const symbol s_11_72[5] = { 'l', 'a', 'o', 'k', 's' };
static const symbol s_11_73[7] = { 'l', 'a', 'o', 'k', 's', 'i', 'd' };
static const symbol s_11_74[8] = { 'l', 'a', 'o', 'k', 's', 'i', 'm', 'e' };
static const symbol s_11_75[7] = { 'l', 'a', 'o', 'k', 's', 'i', 'n' };
static const symbol s_11_76[8] = { 'l', 'a', 'o', 'k', 's', 'i', 't', 'e' };
static const symbol s_11_77[5] = { 'l', 'a', 'o', 'm', 'e' };
static const symbol s_11_78[4] = { 'l', 'a', 'o', 'n' };
static const symbol s_11_79[5] = { 'l', 'a', 'o', 't', 'e' };
static const symbol s_11_80[6] = { 'l', 'a', 'o', 'v', 'a', 'd' };
static const symbol s_11_81[4] = { 'l', 'o', 'e', 'b' };
static const symbol s_11_82[4] = { 'l', 'o', 'e', 'd' };
static const symbol s_11_83[5] = { 'l', 'o', 'e', 'k', 's' };
static const symbol s_11_84[7] = { 'l', 'o', 'e', 'k', 's', 'i', 'd' };
static const symbol s_11_85[8] = { 'l', 'o', 'e', 'k', 's', 'i', 'm', 'e' };
static const symbol s_11_86[7] = { 'l', 'o', 'e', 'k', 's', 'i', 'n' };
static const symbol s_11_87[8] = { 'l', 'o', 'e', 'k', 's', 'i', 't', 'e' };
static const symbol s_11_88[5] = { 'l', 'o', 'e', 'm', 'e' };
static const symbol s_11_89[4] = { 'l', 'o', 'e', 'n' };
static const symbol s_11_90[5] = { 'l', 'o', 'e', 't', 'e' };
static const symbol s_11_91[6] = { 'l', 'o', 'e', 'v', 'a', 'd' };
static const symbol s_11_92[4] = { 'l', 'o', 'o', 'b' };
static const symbol s_11_93[4] = { 'l', 'o', 'o', 'd' };
static const symbol s_11_94[5] = { 'l', 'o', 'o', 'd', 'i' };
static const symbol s_11_95[5] = { 'l', 'o', 'o', 'k', 's' };
static const symbol s_11_96[7] = { 'l', 'o', 'o', 'k', 's', 'i', 'd' };
static const symbol s_11_97[8] = { 'l', 'o', 'o', 'k', 's', 'i', 'm', 'e' };
static const symbol s_11_98[7] = { 'l', 'o', 'o', 'k', 's', 'i', 'n' };
static const symbol s_11_99[8] = { 'l', 'o', 'o', 'k', 's', 'i', 't', 'e' };
static const symbol s_11_100[5] = { 'l', 'o', 'o', 'm', 'a' };
static const symbol s_11_101[7] = { 'l', 'o', 'o', 'm', 'a', 't', 'a' };
static const symbol s_11_102[5] = { 'l', 'o', 'o', 'm', 'e' };
static const symbol s_11_103[4] = { 'l', 'o', 'o', 'n' };
static const symbol s_11_104[5] = { 'l', 'o', 'o', 't', 'e' };
static const symbol s_11_105[6] = { 'l', 'o', 'o', 'v', 'a', 'd' };
static const symbol s_11_106[4] = { 'l', 'u', 'u', 'a' };
static const symbol s_11_107[7] = { 'l', 'u', 'u', 'a', 'k', 's', 'e' };
static const symbol s_11_108[4] = { 'l', 0xC3, 0xB5, 'i' };
static const symbol s_11_109[5] = { 'l', 0xC3, 0xB5, 'i', 'd' };
static const symbol s_11_110[6] = { 'l', 0xC3, 0xB5, 'i', 'm', 'e' };
static const symbol s_11_111[5] = { 'l', 0xC3, 0xB5, 'i', 'n' };
static const symbol s_11_112[6] = { 'l', 0xC3, 0xB5, 'i', 't', 'e' };
static const symbol s_11_113[6] = { 'l', 0xC3, 0xB6, 0xC3, 0xB6, 'b' };
static const symbol s_11_114[6] = { 'l', 0xC3, 0xB6, 0xC3, 0xB6, 'd' };
static const symbol s_11_115[10] = { 'l', 0xC3, 0xB6, 0xC3, 0xB6, 'd', 'a', 'k', 's', 'e' };
static const symbol s_11_116[7] = { 'l', 0xC3, 0xB6, 0xC3, 0xB6, 'd', 'i' };
static const symbol s_11_117[7] = { 'l', 0xC3, 0xB6, 0xC3, 0xB6, 'k', 's' };
static const symbol s_11_118[9] = { 'l', 0xC3, 0xB6, 0xC3, 0xB6, 'k', 's', 'i', 'd' };
static const symbol s_11_119[10] = { 'l', 0xC3, 0xB6, 0xC3, 0xB6, 'k', 's', 'i', 'm', 'e' };
static const symbol s_11_120[9] = { 'l', 0xC3, 0xB6, 0xC3, 0xB6, 'k', 's', 'i', 'n' };
static const symbol s_11_121[10] = { 'l', 0xC3, 0xB6, 0xC3, 0xB6, 'k', 's', 'i', 't', 'e' };
static const symbol s_11_122[7] = { 'l', 0xC3, 0xB6, 0xC3, 0xB6, 'm', 'a' };
static const symbol s_11_123[9] = { 'l', 0xC3, 0xB6, 0xC3, 0xB6, 'm', 'a', 't', 'a' };
static const symbol s_11_124[7] = { 'l', 0xC3, 0xB6, 0xC3, 0xB6, 'm', 'e' };
static const symbol s_11_125[6] = { 'l', 0xC3, 0xB6, 0xC3, 0xB6, 'n' };
static const symbol s_11_126[7] = { 'l', 0xC3, 0xB6, 0xC3, 0xB6, 't', 'e' };
static const symbol s_11_127[8] = { 'l', 0xC3, 0xB6, 0xC3, 0xB6, 'v', 'a', 'd' };
static const symbol s_11_128[6] = { 'l', 0xC3, 0xBC, 0xC3, 0xBC, 'a' };
static const symbol s_11_129[9] = { 'l', 0xC3, 0xBC, 0xC3, 0xBC, 'a', 'k', 's', 'e' };
static const symbol s_11_130[6] = { 'm', 0xC3, 0xBC, 0xC3, 0xBC, 'a' };
static const symbol s_11_131[9] = { 'm', 0xC3, 0xBC, 0xC3, 0xBC, 'a', 'k', 's', 'e' };
static const symbol s_11_132[6] = { 'm', 0xC3, 0xBC, 0xC3, 0xBC, 'b' };
static const symbol s_11_133[6] = { 'm', 0xC3, 0xBC, 0xC3, 0xBC, 'd' };
static const symbol s_11_134[7] = { 'm', 0xC3, 0xBC, 0xC3, 0xBC, 'd', 'i' };
static const symbol s_11_135[7] = { 'm', 0xC3, 0xBC, 0xC3, 0xBC, 'k', 's' };
static const symbol s_11_136[9] = { 'm', 0xC3, 0xBC, 0xC3, 0xBC, 'k', 's', 'i', 'd' };
static const symbol s_11_137[10] = { 'm', 0xC3, 0xBC, 0xC3, 0xBC, 'k', 's', 'i', 'm', 'e' };
static const symbol s_11_138[9] = { 'm', 0xC3, 0xBC, 0xC3, 0xBC, 'k', 's', 'i', 'n' };
static const symbol s_11_139[10] = { 'm', 0xC3, 0xBC, 0xC3, 0xBC, 'k', 's', 'i', 't', 'e' };
static const symbol s_11_140[7] = { 'm', 0xC3, 0xBC, 0xC3, 0xBC, 'm', 'a' };
static const symbol s_11_141[9] = { 'm', 0xC3, 0xBC, 0xC3, 0xBC, 'm', 'a', 't', 'a' };
static const symbol s_11_142[7] = { 'm', 0xC3, 0xBC, 0xC3, 0xBC, 'm', 'e' };
static const symbol s_11_143[6] = { 'm', 0xC3, 0xBC, 0xC3, 0xBC, 'n' };
static const symbol s_11_144[6] = { 'm', 0xC3, 0xBC, 0xC3, 0xBC, 's' };
static const symbol s_11_145[7] = { 'm', 0xC3, 0xBC, 0xC3, 0xBC, 't', 'e' };
static const symbol s_11_146[8] = { 'm', 0xC3, 0xBC, 0xC3, 0xBC, 'v', 'a', 'd' };
static const symbol s_11_147[5] = { 'n', 0xC3, 0xA4, 'e', 'b' };
static const symbol s_11_148[5] = { 'n', 0xC3, 0xA4, 'e', 'd' };
static const symbol s_11_149[6] = { 'n', 0xC3, 0xA4, 'e', 'k', 's' };
static const symbol s_11_150[8] = { 'n', 0xC3, 0xA4, 'e', 'k', 's', 'i', 'd' };
static const symbol s_11_151[9] = { 'n', 0xC3, 0xA4, 'e', 'k', 's', 'i', 'm', 'e' };
static const symbol s_11_152[8] = { 'n', 0xC3, 0xA4, 'e', 'k', 's', 'i', 'n' };
static const symbol s_11_153[9] = { 'n', 0xC3, 0xA4, 'e', 'k', 's', 'i', 't', 'e' };
static const symbol s_11_154[6] = { 'n', 0xC3, 0xA4, 'e', 'm', 'e' };
static const symbol s_11_155[5] = { 'n', 0xC3, 0xA4, 'e', 'n' };
static const symbol s_11_156[6] = { 'n', 0xC3, 0xA4, 'e', 't', 'e' };
static const symbol s_11_157[7] = { 'n', 0xC3, 0xA4, 'e', 'v', 'a', 'd' };
static const symbol s_11_158[7] = { 'n', 0xC3, 0xA4, 'g', 'e', 'm', 'a' };
static const symbol s_11_159[9] = { 'n', 0xC3, 0xA4, 'g', 'e', 'm', 'a', 't', 'a' };
static const symbol s_11_160[5] = { 'n', 0xC3, 0xA4, 'h', 'a' };
static const symbol s_11_161[8] = { 'n', 0xC3, 0xA4, 'h', 'a', 'k', 's', 'e' };
static const symbol s_11_162[6] = { 'n', 0xC3, 0xA4, 'h', 't', 'i' };
static const symbol s_11_163[5] = { 'p', 0xC3, 0xB5, 'e', 'b' };
static const symbol s_11_164[5] = { 'p', 0xC3, 0xB5, 'e', 'd' };
static const symbol s_11_165[6] = { 'p', 0xC3, 0xB5, 'e', 'k', 's' };
static const symbol s_11_166[8] = { 'p', 0xC3, 0xB5, 'e', 'k', 's', 'i', 'd' };
static const symbol s_11_167[9] = { 'p', 0xC3, 0xB5, 'e', 'k', 's', 'i', 'm', 'e' };
static const symbol s_11_168[8] = { 'p', 0xC3, 0xB5, 'e', 'k', 's', 'i', 'n' };
static const symbol s_11_169[9] = { 'p', 0xC3, 0xB5, 'e', 'k', 's', 'i', 't', 'e' };
static const symbol s_11_170[6] = { 'p', 0xC3, 0xB5, 'e', 'm', 'e' };
static const symbol s_11_171[5] = { 'p', 0xC3, 0xB5, 'e', 'n' };
static const symbol s_11_172[6] = { 'p', 0xC3, 0xB5, 'e', 't', 'e' };
static const symbol s_11_173[7] = { 'p', 0xC3, 0xB5, 'e', 'v', 'a', 'd' };
static const symbol s_11_174[4] = { 's', 'a', 'a', 'b' };
static const symbol s_11_175[4] = { 's', 'a', 'a', 'd' };
static const symbol s_11_176[5] = { 's', 'a', 'a', 'd', 'a' };
static const symbol s_11_177[8] = { 's', 'a', 'a', 'd', 'a', 'k', 's', 'e' };
static const symbol s_11_178[5] = { 's', 'a', 'a', 'd', 'i' };
static const symbol s_11_179[5] = { 's', 'a', 'a', 'k', 's' };
static const symbol s_11_180[7] = { 's', 'a', 'a', 'k', 's', 'i', 'd' };
static const symbol s_11_181[8] = { 's', 'a', 'a', 'k', 's', 'i', 'm', 'e' };
static const symbol s_11_182[7] = { 's', 'a', 'a', 'k', 's', 'i', 'n' };
static const symbol s_11_183[8] = { 's', 'a', 'a', 'k', 's', 'i', 't', 'e' };
static const symbol s_11_184[5] = { 's', 'a', 'a', 'm', 'a' };
static const symbol s_11_185[7] = { 's', 'a', 'a', 'm', 'a', 't', 'a' };
static const symbol s_11_186[5] = { 's', 'a', 'a', 'm', 'e' };
static const symbol s_11_187[4] = { 's', 'a', 'a', 'n' };
static const symbol s_11_188[5] = { 's', 'a', 'a', 't', 'e' };
static const symbol s_11_189[6] = { 's', 'a', 'a', 'v', 'a', 'd' };
static const symbol s_11_190[3] = { 's', 'a', 'i' };
static const symbol s_11_191[4] = { 's', 'a', 'i', 'd' };
static const symbol s_11_192[5] = { 's', 'a', 'i', 'm', 'e' };
static const symbol s_11_193[4] = { 's', 'a', 'i', 'n' };
static const symbol s_11_194[5] = { 's', 'a', 'i', 't', 'e' };
static const symbol s_11_195[4] = { 's', 0xC3, 0xB5, 'i' };
static const symbol s_11_196[5] = { 's', 0xC3, 0xB5, 'i', 'd' };
static const symbol s_11_197[6] = { 's', 0xC3, 0xB5, 'i', 'm', 'e' };
static const symbol s_11_198[5] = { 's', 0xC3, 0xB5, 'i', 'n' };
static const symbol s_11_199[6] = { 's', 0xC3, 0xB5, 'i', 't', 'e' };
static const symbol s_11_200[6] = { 's', 0xC3, 0xB6, 0xC3, 0xB6, 'b' };
static const symbol s_11_201[6] = { 's', 0xC3, 0xB6, 0xC3, 0xB6, 'd' };
static const symbol s_11_202[10] = { 's', 0xC3, 0xB6, 0xC3, 0xB6, 'd', 'a', 'k', 's', 'e' };
static const symbol s_11_203[7] = { 's', 0xC3, 0xB6, 0xC3, 0xB6, 'd', 'i' };
static const symbol s_11_204[7] = { 's', 0xC3, 0xB6, 0xC3, 0xB6, 'k', 's' };
static const symbol s_11_205[9] = { 's', 0xC3, 0xB6, 0xC3, 0xB6, 'k', 's', 'i', 'd' };
static const symbol s_11_206[10] = { 's', 0xC3, 0xB6, 0xC3, 0xB6, 'k', 's', 'i', 'm', 'e' };
static const symbol s_11_207[9] = { 's', 0xC3, 0xB6, 0xC3, 0xB6, 'k', 's', 'i', 'n' };
static const symbol s_11_208[10] = { 's', 0xC3, 0xB6, 0xC3, 0xB6, 'k', 's', 'i', 't', 'e' };
static const symbol s_11_209[7] = { 's', 0xC3, 0xB6, 0xC3, 0xB6, 'm', 'a' };
static const symbol s_11_210[9] = { 's', 0xC3, 0xB6, 0xC3, 0xB6, 'm', 'a', 't', 'a' };
static const symbol s_11_211[7] = { 's', 0xC3, 0xB6, 0xC3, 0xB6, 'm', 'e' };
static const symbol s_11_212[6] = { 's', 0xC3, 0xB6, 0xC3, 0xB6, 'n' };
static const symbol s_11_213[7] = { 's', 0xC3, 0xB6, 0xC3, 0xB6, 't', 'e' };
static const symbol s_11_214[8] = { 's', 0xC3, 0xB6, 0xC3, 0xB6, 'v', 'a', 'd' };
static const symbol s_11_215[6] = { 's', 0xC3, 0xBC, 0xC3, 0xBC, 'a' };
static const symbol s_11_216[9] = { 's', 0xC3, 0xBC, 0xC3, 0xBC, 'a', 'k', 's', 'e' };
static const symbol s_11_217[4] = { 't', 'e', 'e', 'b' };
static const symbol s_11_218[4] = { 't', 'e', 'e', 'd' };
static const symbol s_11_219[5] = { 't', 'e', 'e', 'k', 's' };
static const symbol s_11_220[7] = { 't', 'e', 'e', 'k', 's', 'i', 'd' };
static const symbol s_11_221[8] = { 't', 'e', 'e', 'k', 's', 'i', 'm', 'e' };
static const symbol s_11_222[7] = { 't', 'e', 'e', 'k', 's', 'i', 'n' };
static const symbol s_11_223[8] = { 't', 'e', 'e', 'k', 's', 'i', 't', 'e' };
static const symbol s_11_224[5] = { 't', 'e', 'e', 'm', 'e' };
static const symbol s_11_225[4] = { 't', 'e', 'e', 'n' };
static const symbol s_11_226[5] = { 't', 'e', 'e', 't', 'e' };
static const symbol s_11_227[6] = { 't', 'e', 'e', 'v', 'a', 'd' };
static const symbol s_11_228[6] = { 't', 'e', 'g', 'e', 'm', 'a' };
static const symbol s_11_229[8] = { 't', 'e', 'g', 'e', 'm', 'a', 't', 'a' };
static const symbol s_11_230[4] = { 't', 'e', 'h', 'a' };
static const symbol s_11_231[7] = { 't', 'e', 'h', 'a', 'k', 's', 'e' };
static const symbol s_11_232[5] = { 't', 'e', 'h', 't', 'i' };
static const symbol s_11_233[4] = { 't', 'o', 'o', 'b' };
static const symbol s_11_234[4] = { 't', 'o', 'o', 'd' };
static const symbol s_11_235[5] = { 't', 'o', 'o', 'd', 'i' };
static const symbol s_11_236[5] = { 't', 'o', 'o', 'k', 's' };
static const symbol s_11_237[7] = { 't', 'o', 'o', 'k', 's', 'i', 'd' };
static const symbol s_11_238[8] = { 't', 'o', 'o', 'k', 's', 'i', 'm', 'e' };
static const symbol s_11_239[7] = { 't', 'o', 'o', 'k', 's', 'i', 'n' };
static const symbol s_11_240[8] = { 't', 'o', 'o', 'k', 's', 'i', 't', 'e' };
static const symbol s_11_241[5] = { 't', 'o', 'o', 'm', 'a' };
static const symbol s_11_242[7] = { 't', 'o', 'o', 'm', 'a', 't', 'a' };
static const symbol s_11_243[5] = { 't', 'o', 'o', 'm', 'e' };
static const symbol s_11_244[4] = { 't', 'o', 'o', 'n' };
static const symbol s_11_245[5] = { 't', 'o', 'o', 't', 'e' };
static const symbol s_11_246[6] = { 't', 'o', 'o', 'v', 'a', 'd' };
static const symbol s_11_247[4] = { 't', 'u', 'u', 'a' };
static const symbol s_11_248[7] = { 't', 'u', 'u', 'a', 'k', 's', 'e' };
static const symbol s_11_249[4] = { 't', 0xC3, 0xB5, 'i' };
static const symbol s_11_250[5] = { 't', 0xC3, 0xB5, 'i', 'd' };
static const symbol s_11_251[6] = { 't', 0xC3, 0xB5, 'i', 'm', 'e' };
static const symbol s_11_252[5] = { 't', 0xC3, 0xB5, 'i', 'n' };
static const symbol s_11_253[6] = { 't', 0xC3, 0xB5, 'i', 't', 'e' };
static const symbol s_11_254[4] = { 'v', 'i', 'i', 'a' };
static const symbol s_11_255[7] = { 'v', 'i', 'i', 'a', 'k', 's', 'e' };
static const symbol s_11_256[4] = { 'v', 'i', 'i', 'b' };
static const symbol s_11_257[4] = { 'v', 'i', 'i', 'd' };
static const symbol s_11_258[5] = { 'v', 'i', 'i', 'd', 'i' };
static const symbol s_11_259[5] = { 'v', 'i', 'i', 'k', 's' };
static const symbol s_11_260[7] = { 'v', 'i', 'i', 'k', 's', 'i', 'd' };
static const symbol s_11_261[8] = { 'v', 'i', 'i', 'k', 's', 'i', 'm', 'e' };
static const symbol s_11_262[7] = { 'v', 'i', 'i', 'k', 's', 'i', 'n' };
static const symbol s_11_263[8] = { 'v', 'i', 'i', 'k', 's', 'i', 't', 'e' };
static const symbol s_11_264[5] = { 'v', 'i', 'i', 'm', 'a' };
static const symbol s_11_265[7] = { 'v', 'i', 'i', 'm', 'a', 't', 'a' };
static const symbol s_11_266[5] = { 'v', 'i', 'i', 'm', 'e' };
static const symbol s_11_267[4] = { 'v', 'i', 'i', 'n' };
static const symbol s_11_268[7] = { 'v', 'i', 'i', 's', 'i', 'm', 'e' };
static const symbol s_11_269[6] = { 'v', 'i', 'i', 's', 'i', 'n' };
static const symbol s_11_270[7] = { 'v', 'i', 'i', 's', 'i', 't', 'e' };
static const symbol s_11_271[5] = { 'v', 'i', 'i', 't', 'e' };
static const symbol s_11_272[6] = { 'v', 'i', 'i', 'v', 'a', 'd' };
static const symbol s_11_273[5] = { 'v', 0xC3, 0xB5, 'i', 'b' };
static const symbol s_11_274[5] = { 'v', 0xC3, 0xB5, 'i', 'd' };
static const symbol s_11_275[6] = { 'v', 0xC3, 0xB5, 'i', 'd', 'a' };
static const symbol s_11_276[9] = { 'v', 0xC3, 0xB5, 'i', 'd', 'a', 'k', 's', 'e' };
static const symbol s_11_277[6] = { 'v', 0xC3, 0xB5, 'i', 'd', 'i' };
static const symbol s_11_278[6] = { 'v', 0xC3, 0xB5, 'i', 'k', 's' };
static const symbol s_11_279[8] = { 'v', 0xC3, 0xB5, 'i', 'k', 's', 'i', 'd' };
static const symbol s_11_280[9] = { 'v', 0xC3, 0xB5, 'i', 'k', 's', 'i', 'm', 'e' };
static const symbol s_11_281[8] = { 'v', 0xC3, 0xB5, 'i', 'k', 's', 'i', 'n' };
static const symbol s_11_282[9] = { 'v', 0xC3, 0xB5, 'i', 'k', 's', 'i', 't', 'e' };
static const symbol s_11_283[6] = { 'v', 0xC3, 0xB5, 'i', 'm', 'a' };
static const symbol s_11_284[8] = { 'v', 0xC3, 0xB5, 'i', 'm', 'a', 't', 'a' };
static const symbol s_11_285[6] = { 'v', 0xC3, 0xB5, 'i', 'm', 'e' };
static const symbol s_11_286[5] = { 'v', 0xC3, 0xB5, 'i', 'n' };
static const symbol s_11_287[5] = { 'v', 0xC3, 0xB5, 'i', 's' };
static const symbol s_11_288[6] = { 'v', 0xC3, 0xB5, 'i', 't', 'e' };
static const symbol s_11_289[7] = { 'v', 0xC3, 0xB5, 'i', 'v', 'a', 'd' };
static const struct among a_11[290] = {
{ 4, s_11_0, 0, 1, 0},
{ 4, s_11_1, 0, 1, 0},
{ 8, s_11_2, -1, 1, 0},
{ 5, s_11_3, 0, 1, 0},
{ 7, s_11_4, -1, 1, 0},
{ 5, s_11_5, 0, 1, 0},
{ 4, s_11_6, 0, 1, 0},
{ 5, s_11_7, 0, 1, 0},
{ 6, s_11_8, 0, 1, 0},
{ 4, s_11_9, 0, 1, 0},
{ 7, s_11_10, -1, 1, 0},
{ 4, s_11_11, 0, 12, 0},
{ 5, s_11_12, -1, 12, 0},
{ 6, s_11_13, -2, 12, 0},
{ 5, s_11_14, -3, 12, 0},
{ 6, s_11_15, -4, 12, 0},
{ 6, s_11_16, 0, 12, 0},
{ 6, s_11_17, 0, 12, 0},
{ 7, s_11_18, -1, 12, 0},
{ 10, s_11_19, -1, 12, 0},
{ 7, s_11_20, -3, 12, 0},
{ 7, s_11_21, 0, 12, 0},
{ 9, s_11_22, -1, 12, 0},
{ 10, s_11_23, -2, 12, 0},
{ 9, s_11_24, -3, 12, 0},
{ 10, s_11_25, -4, 12, 0},
{ 7, s_11_26, 0, 12, 0},
{ 9, s_11_27, -1, 12, 0},
{ 7, s_11_28, 0, 12, 0},
{ 6, s_11_29, 0, 12, 0},
{ 7, s_11_30, 0, 12, 0},
{ 8, s_11_31, 0, 12, 0},
{ 4, s_11_32, 0, 1, 0},
{ 5, s_11_33, -1, 1, 0},
{ 6, s_11_34, -2, 1, 0},
{ 5, s_11_35, -3, 1, 0},
{ 6, s_11_36, -4, 1, 0},
{ 4, s_11_37, 0, 4, 0},
{ 4, s_11_38, 0, 4, 0},
{ 8, s_11_39, -1, 4, 0},
{ 5, s_11_40, 0, 4, 0},
{ 7, s_11_41, -1, 4, 0},
{ 8, s_11_42, -2, 4, 0},
{ 7, s_11_43, -3, 4, 0},
{ 8, s_11_44, -4, 4, 0},
{ 5, s_11_45, 0, 4, 0},
{ 7, s_11_46, -1, 4, 0},
{ 5, s_11_47, 0, 4, 0},
{ 4, s_11_48, 0, 4, 0},
{ 4, s_11_49, 0, 4, 0},
{ 5, s_11_50, 0, 4, 0},
{ 5, s_11_51, 0, 4, 0},
{ 6, s_11_52, 0, 4, 0},
{ 5, s_11_53, 0, 8, 0},
{ 8, s_11_54, -1, 8, 0},
{ 5, s_11_55, 0, 8, 0},
{ 5, s_11_56, 0, 8, 0},
{ 6, s_11_57, -1, 8, 0},
{ 6, s_11_58, 0, 8, 0},
{ 8, s_11_59, -1, 8, 0},
{ 9, s_11_60, -2, 8, 0},
{ 8, s_11_61, -3, 8, 0},
{ 9, s_11_62, -4, 8, 0},
{ 6, s_11_63, 0, 8, 0},
{ 8, s_11_64, -1, 8, 0},
{ 6, s_11_65, 0, 8, 0},
{ 5, s_11_66, 0, 8, 0},
{ 5, s_11_67, 0, 8, 0},
{ 6, s_11_68, 0, 8, 0},
{ 7, s_11_69, 0, 8, 0},
{ 4, s_11_70, 0, 16, 0},
{ 4, s_11_71, 0, 16, 0},
{ 5, s_11_72, 0, 16, 0},
{ 7, s_11_73, -1, 16, 0},
{ 8, s_11_74, -2, 16, 0},
{ 7, s_11_75, -3, 16, 0},
{ 8, s_11_76, -4, 16, 0},
{ 5, s_11_77, 0, 16, 0},
{ 4, s_11_78, 0, 16, 0},
{ 5, s_11_79, 0, 16, 0},
{ 6, s_11_80, 0, 16, 0},
{ 4, s_11_81, 0, 14, 0},
{ 4, s_11_82, 0, 14, 0},
{ 5, s_11_83, 0, 14, 0},
{ 7, s_11_84, -1, 14, 0},
{ 8, s_11_85, -2, 14, 0},
{ 7, s_11_86, -3, 14, 0},
{ 8, s_11_87, -4, 14, 0},
{ 5, s_11_88, 0, 14, 0},
{ 4, s_11_89, 0, 14, 0},
{ 5, s_11_90, 0, 14, 0},
{ 6, s_11_91, 0, 14, 0},
{ 4, s_11_92, 0, 7, 0},
{ 4, s_11_93, 0, 7, 0},
{ 5, s_11_94, -1, 7, 0},
{ 5, s_11_95, 0, 7, 0},
{ 7, s_11_96, -1, 7, 0},
{ 8, s_11_97, -2, 7, 0},
{ 7, s_11_98, -3, 7, 0},
{ 8, s_11_99, -4, 7, 0},
{ 5, s_11_100, 0, 7, 0},
{ 7, s_11_101, -1, 7, 0},
{ 5, s_11_102, 0, 7, 0},
{ 4, s_11_103, 0, 7, 0},
{ 5, s_11_104, 0, 7, 0},
{ 6, s_11_105, 0, 7, 0},
{ 4, s_11_106, 0, 7, 0},
{ 7, s_11_107, -1, 7, 0},
{ 4, s_11_108, 0, 6, 0},
{ 5, s_11_109, -1, 6, 0},
{ 6, s_11_110, -2, 6, 0},
{ 5, s_11_111, -3, 6, 0},
{ 6, s_11_112, -4, 6, 0},
{ 6, s_11_113, 0, 5, 0},
{ 6, s_11_114, 0, 5, 0},
{ 10, s_11_115, -1, 5, 0},
{ 7, s_11_116, -2, 5, 0},
{ 7, s_11_117, 0, 5, 0},
{ 9, s_11_118, -1, 5, 0},
{ 10, s_11_119, -2, 5, 0},
{ 9, s_11_120, -3, 5, 0},
{ 10, s_11_121, -4, 5, 0},
{ 7, s_11_122, 0, 5, 0},
{ 9, s_11_123, -1, 5, 0},
{ 7, s_11_124, 0, 5, 0},
{ 6, s_11_125, 0, 5, 0},
{ 7, s_11_126, 0, 5, 0},
{ 8, s_11_127, 0, 5, 0},
{ 6, s_11_128, 0, 5, 0},
{ 9, s_11_129, -1, 5, 0},
{ 6, s_11_130, 0, 13, 0},
{ 9, s_11_131, -1, 13, 0},
{ 6, s_11_132, 0, 13, 0},
{ 6, s_11_133, 0, 13, 0},
{ 7, s_11_134, -1, 13, 0},
{ 7, s_11_135, 0, 13, 0},
{ 9, s_11_136, -1, 13, 0},
{ 10, s_11_137, -2, 13, 0},
{ 9, s_11_138, -3, 13, 0},
{ 10, s_11_139, -4, 13, 0},
{ 7, s_11_140, 0, 13, 0},
{ 9, s_11_141, -1, 13, 0},
{ 7, s_11_142, 0, 13, 0},
{ 6, s_11_143, 0, 13, 0},
{ 6, s_11_144, 0, 13, 0},
{ 7, s_11_145, 0, 13, 0},
{ 8, s_11_146, 0, 13, 0},
{ 5, s_11_147, 0, 18, 0},
{ 5, s_11_148, 0, 18, 0},
{ 6, s_11_149, 0, 18, 0},
{ 8, s_11_150, -1, 18, 0},
{ 9, s_11_151, -2, 18, 0},
{ 8, s_11_152, -3, 18, 0},
{ 9, s_11_153, -4, 18, 0},
{ 6, s_11_154, 0, 18, 0},
{ 5, s_11_155, 0, 18, 0},
{ 6, s_11_156, 0, 18, 0},
{ 7, s_11_157, 0, 18, 0},
{ 7, s_11_158, 0, 18, 0},
{ 9, s_11_159, -1, 18, 0},
{ 5, s_11_160, 0, 18, 0},
{ 8, s_11_161, -1, 18, 0},
{ 6, s_11_162, 0, 18, 0},
{ 5, s_11_163, 0, 15, 0},
{ 5, s_11_164, 0, 15, 0},
{ 6, s_11_165, 0, 15, 0},
{ 8, s_11_166, -1, 15, 0},
{ 9, s_11_167, -2, 15, 0},
{ 8, s_11_168, -3, 15, 0},
{ 9, s_11_169, -4, 15, 0},
{ 6, s_11_170, 0, 15, 0},
{ 5, s_11_171, 0, 15, 0},
{ 6, s_11_172, 0, 15, 0},
{ 7, s_11_173, 0, 15, 0},
{ 4, s_11_174, 0, 2, 0},
{ 4, s_11_175, 0, 2, 0},
{ 5, s_11_176, -1, 2, 0},
{ 8, s_11_177, -1, 2, 0},
{ 5, s_11_178, -3, 2, 0},
{ 5, s_11_179, 0, 2, 0},
{ 7, s_11_180, -1, 2, 0},
{ 8, s_11_181, -2, 2, 0},
{ 7, s_11_182, -3, 2, 0},
{ 8, s_11_183, -4, 2, 0},
{ 5, s_11_184, 0, 2, 0},
{ 7, s_11_185, -1, 2, 0},
{ 5, s_11_186, 0, 2, 0},
{ 4, s_11_187, 0, 2, 0},
{ 5, s_11_188, 0, 2, 0},
{ 6, s_11_189, 0, 2, 0},
{ 3, s_11_190, 0, 2, 0},
{ 4, s_11_191, -1, 2, 0},
{ 5, s_11_192, -2, 2, 0},
{ 4, s_11_193, -3, 2, 0},
{ 5, s_11_194, -4, 2, 0},
{ 4, s_11_195, 0, 9, 0},
{ 5, s_11_196, -1, 9, 0},
{ 6, s_11_197, -2, 9, 0},
{ 5, s_11_198, -3, 9, 0},
{ 6, s_11_199, -4, 9, 0},
{ 6, s_11_200, 0, 9, 0},
{ 6, s_11_201, 0, 9, 0},
{ 10, s_11_202, -1, 9, 0},
{ 7, s_11_203, -2, 9, 0},
{ 7, s_11_204, 0, 9, 0},
{ 9, s_11_205, -1, 9, 0},
{ 10, s_11_206, -2, 9, 0},
{ 9, s_11_207, -3, 9, 0},
{ 10, s_11_208, -4, 9, 0},
{ 7, s_11_209, 0, 9, 0},
{ 9, s_11_210, -1, 9, 0},
{ 7, s_11_211, 0, 9, 0},
{ 6, s_11_212, 0, 9, 0},
{ 7, s_11_213, 0, 9, 0},
{ 8, s_11_214, 0, 9, 0},
{ 6, s_11_215, 0, 9, 0},
{ 9, s_11_216, -1, 9, 0},
{ 4, s_11_217, 0, 17, 0},
{ 4, s_11_218, 0, 17, 0},
{ 5, s_11_219, 0, 17, 0},
{ 7, s_11_220, -1, 17, 0},
{ 8, s_11_221, -2, 17, 0},
{ 7, s_11_222, -3, 17, 0},
{ 8, s_11_223, -4, 17, 0},
{ 5, s_11_224, 0, 17, 0},
{ 4, s_11_225, 0, 17, 0},
{ 5, s_11_226, 0, 17, 0},
{ 6, s_11_227, 0, 17, 0},
{ 6, s_11_228, 0, 17, 0},
{ 8, s_11_229, -1, 17, 0},
{ 4, s_11_230, 0, 17, 0},
{ 7, s_11_231, -1, 17, 0},
{ 5, s_11_232, 0, 17, 0},
{ 4, s_11_233, 0, 10, 0},
{ 4, s_11_234, 0, 10, 0},
{ 5, s_11_235, -1, 10, 0},
{ 5, s_11_236, 0, 10, 0},
{ 7, s_11_237, -1, 10, 0},
{ 8, s_11_238, -2, 10, 0},
{ 7, s_11_239, -3, 10, 0},
{ 8, s_11_240, -4, 10, 0},
{ 5, s_11_241, 0, 10, 0},
{ 7, s_11_242, -1, 10, 0},
{ 5, s_11_243, 0, 10, 0},
{ 4, s_11_244, 0, 10, 0},
{ 5, s_11_245, 0, 10, 0},
{ 6, s_11_246, 0, 10, 0},
{ 4, s_11_247, 0, 10, 0},
{ 7, s_11_248, -1, 10, 0},
{ 4, s_11_249, 0, 10, 0},
{ 5, s_11_250, -1, 10, 0},
{ 6, s_11_251, -2, 10, 0},
{ 5, s_11_252, -3, 10, 0},
{ 6, s_11_253, -4, 10, 0},
{ 4, s_11_254, 0, 3, 0},
{ 7, s_11_255, -1, 3, 0},
{ 4, s_11_256, 0, 3, 0},
{ 4, s_11_257, 0, 3, 0},
{ 5, s_11_258, -1, 3, 0},
{ 5, s_11_259, 0, 3, 0},
{ 7, s_11_260, -1, 3, 0},
{ 8, s_11_261, -2, 3, 0},
{ 7, s_11_262, -3, 3, 0},
{ 8, s_11_263, -4, 3, 0},
{ 5, s_11_264, 0, 3, 0},
{ 7, s_11_265, -1, 3, 0},
{ 5, s_11_266, 0, 3, 0},
{ 4, s_11_267, 0, 3, 0},
{ 7, s_11_268, 0, 3, 0},
{ 6, s_11_269, 0, 3, 0},
{ 7, s_11_270, 0, 3, 0},
{ 5, s_11_271, 0, 3, 0},
{ 6, s_11_272, 0, 3, 0},
{ 5, s_11_273, 0, 11, 0},
{ 5, s_11_274, 0, 11, 0},
{ 6, s_11_275, -1, 11, 0},
{ 9, s_11_276, -1, 11, 0},
{ 6, s_11_277, -3, 11, 0},
{ 6, s_11_278, 0, 11, 0},
{ 8, s_11_279, -1, 11, 0},
{ 9, s_11_280, -2, 11, 0},
{ 8, s_11_281, -3, 11, 0},
{ 9, s_11_282, -4, 11, 0},
{ 6, s_11_283, 0, 11, 0},
{ 8, s_11_284, -1, 11, 0},
{ 6, s_11_285, 0, 11, 0},
{ 5, s_11_286, 0, 11, 0},
{ 5, s_11_287, 0, 11, 0},
{ 6, s_11_288, 0, 11, 0},
{ 7, s_11_289, 0, 11, 0}
};

static const unsigned char g_V1[] = { 17, 65, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 48, 8 };

static const unsigned char g_RV[] = { 17, 65, 16 };

static const unsigned char g_KI[] = { 117, 66, 6, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 0, 0, 0, 16 };

static const unsigned char g_GI[] = { 21, 123, 243, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 48, 8 };

static const symbol s_0[] = { 'a' };
static const symbol s_1[] = { 'l', 'a', 's', 'e' };
static const symbol s_2[] = { 'm', 'i', 's', 'e' };
static const symbol s_3[] = { 'l', 'i', 's', 'e' };
static const symbol s_4[] = { 'i', 'k', 'u' };
static const symbol s_5[] = { 'e' };
static const symbol s_6[] = { 't' };
static const symbol s_7[] = { 'k' };
static const symbol s_8[] = { 'p' };
static const symbol s_9[] = { 't' };
static const symbol s_10[] = { 'j', 'o', 'o' };
static const symbol s_11[] = { 's', 'a', 'a' };
static const symbol s_12[] = { 'v', 'i', 'i', 'm', 'a' };
static const symbol s_13[] = { 'k', 'e', 'e', 's', 'i' };
static const symbol s_14[] = { 'l', 0xC3, 0xB6, 0xC3, 0xB6 };
static const symbol s_15[] = { 'l', 0xC3, 0xB5, 'i' };
static const symbol s_16[] = { 'l', 'o', 'o' };
static const symbol s_17[] = { 'k', 0xC3, 0xA4, 'i', 's', 'i' };
static const symbol s_18[] = { 's', 0xC3, 0xB6, 0xC3, 0xB6 };
static const symbol s_19[] = { 't', 'o', 'o' };
static const symbol s_20[] = { 'v', 0xC3, 0xB5, 'i', 's', 'i' };
static const symbol s_21[] = { 'j', 0xC3, 0xA4, 0xC3, 0xA4, 'm', 'a' };
static const symbol s_22[] = { 'm', 0xC3, 0xBC, 0xC3, 0xBC, 's', 'i' };
static const symbol s_23[] = { 'l', 'u', 'g', 'e' };
static const symbol s_24[] = { 'p', 0xC3, 0xB5, 'd', 'e' };
static const symbol s_25[] = { 'l', 'a', 'd', 'u' };
static const symbol s_26[] = { 't', 'e', 'g', 'i' };
static const symbol s_27[] = { 'n', 0xC3, 0xA4, 'g', 'i' };

static int r_mark_regions(struct SN_env * z) {
    z->I[0] = z->l;
    {
        int ret = out_grouping_U(z, g_V1, 97, 252, 1);
        if (ret < 0) return 0;
        z->c += ret;
    }
    {
        int ret = in_grouping_U(z, g_V1, 97, 252, 1);
        if (ret < 0) return 0;
        z->c += ret;
    }
    z->I[0] = z->c;
    return 1;
}

static int r_emphasis(struct SN_env * z) {
    int among_var;

    {
        int v_1;
        if (z->c < z->I[0]) return 0;
        v_1 = z->lb; z->lb = z->I[0];
        z->ket = z->c;
        if (z->c - 1 <= z->lb || z->p[z->c - 1] != 105) { z->lb = v_1; return 0; }
        among_var = find_among_b(z, a_0, 2);
        if (!among_var) { z->lb = v_1; return 0; }
        z->bra = z->c;
        z->lb = v_1;
    }
    {
        int v_2 = z->l - z->c;
        {
            int ret = skip_b_utf8(z->p, z->c, z->lb, 4);
            if (ret < 0) return 0;
            z->c = ret;
        }
        z->c = z->l - v_2;
    }
    switch (among_var) {
        case 1:
            {
                int v_3 = z->l - z->c;
                if (in_grouping_b_U(z, g_GI, 97, 252, 0)) return 0;
                z->c = z->l - v_3;
                {
                    int v_4 = z->l - z->c;
                    {
                        int ret = r_LONGV(z);
                        if (ret == 0) goto lab0;
                        if (ret < 0) return ret;
                    }
                    return 0;
                lab0:
                    z->c = z->l - v_4;
                }
            }
            {
                int ret = slice_del(z);
                if (ret < 0) return ret;
            }
            break;
        case 2:
            if (in_grouping_b_U(z, g_KI, 98, 382, 0)) return 0;
            {
                int ret = slice_del(z);
                if (ret < 0) return ret;
            }
            break;
    }
    return 1;
}

static int r_verb(struct SN_env * z) {
    int among_var;

    {
        int v_1;
        if (z->c < z->I[0]) return 0;
        v_1 = z->lb; z->lb = z->I[0];
        z->ket = z->c;
        if (z->c <= z->lb || z->p[z->c - 1] >> 5 != 3 || !((540726 >> (z->p[z->c - 1] & 0x1f)) & 1)) { z->lb = v_1; return 0; }
        among_var = find_among_b(z, a_1, 21);
        if (!among_var) { z->lb = v_1; return 0; }
        z->bra = z->c;
        z->lb = v_1;
    }
    switch (among_var) {
        case 1:
            {
                int ret = slice_del(z);
                if (ret < 0) return ret;
            }
            break;
        case 2:
            {
                int ret = slice_from_s(z, 1, s_0);
                if (ret < 0) return ret;
            }
            break;
        case 3:
            if (in_grouping_b_U(z, g_V1, 97, 252, 0)) return 0;
            {
                int ret = slice_del(z);
                if (ret < 0) return ret;
            }
            break;
    }
    return 1;
}

static int r_LONGV(struct SN_env * z) {
    if (!find_among_b(z, a_2, 9)) return 0;
    return 1;
}

static int r_i_plural(struct SN_env * z) {

    {
        int v_1;
        if (z->c < z->I[0]) return 0;
        v_1 = z->lb; z->lb = z->I[0];
        z->ket = z->c;
        if (z->c <= z->lb || z->p[z->c - 1] != 105) { z->lb = v_1; return 0; }
        if (!find_among_b(z, a_3, 1)) { z->lb = v_1; return 0; }
        z->bra = z->c;
        z->lb = v_1;
    }
    if (in_grouping_b_U(z, g_RV, 97, 117, 0)) return 0;
    {
        int ret = slice_del(z);
        if (ret < 0) return ret;
    }
    return 1;
}

static int r_special_noun_endings(struct SN_env * z) {
    int among_var;

    {
        int v_1;
        if (z->c < z->I[0]) return 0;
        v_1 = z->lb; z->lb = z->I[0];
        z->ket = z->c;
        if (z->c - 3 <= z->lb || z->p[z->c - 1] >> 5 != 3 || !((1049120 >> (z->p[z->c - 1] & 0x1f)) & 1)) { z->lb = v_1; return 0; }
        among_var = find_among_b(z, a_4, 12);
        if (!among_var) { z->lb = v_1; return 0; }
        z->bra = z->c;
        z->lb = v_1;
    }
    switch (among_var) {
        case 1:
            {
                int ret = slice_from_s(z, 4, s_1);
                if (ret < 0) return ret;
            }
            break;
        case 2:
            {
                int ret = slice_from_s(z, 4, s_2);
                if (ret < 0) return ret;
            }
            break;
        case 3:
            {
                int ret = slice_from_s(z, 4, s_3);
                if (ret < 0) return ret;
            }
            break;
    }
    return 1;
}

static int r_case_ending(struct SN_env * z) {
    int among_var;

    {
        int v_1;
        if (z->c < z->I[0]) return 0;
        v_1 = z->lb; z->lb = z->I[0];
        z->ket = z->c;
        if (z->c <= z->lb || z->p[z->c - 1] >> 5 != 3 || !((1576994 >> (z->p[z->c - 1] & 0x1f)) & 1)) { z->lb = v_1; return 0; }
        among_var = find_among_b(z, a_5, 10);
        if (!among_var) { z->lb = v_1; return 0; }
        z->bra = z->c;
        z->lb = v_1;
    }
    switch (among_var) {
        case 1:
            {
                int v_2 = z->l - z->c;
                if (in_grouping_b_U(z, g_RV, 97, 117, 0)) goto lab1;
                goto lab0;
            lab1:
                z->c = z->l - v_2;
                {
                    int ret = r_LONGV(z);
                    if (ret <= 0) return ret;
                }
            }
        lab0:
            break;
        case 2:
            {
                int v_3 = z->l - z->c;
                {
                    int ret = skip_b_utf8(z->p, z->c, z->lb, 4);
                    if (ret < 0) return 0;
                    z->c = ret;
                }
                z->c = z->l - v_3;
            }
            break;
    }
    {
        int ret = slice_del(z);
        if (ret < 0) return ret;
    }
    return 1;
}

static int r_plural_three_first_cases(struct SN_env * z) {
    int among_var;

    {
        int v_1;
        if (z->c < z->I[0]) return 0;
        v_1 = z->lb; z->lb = z->I[0];
        z->ket = z->c;
        if (z->c <= z->lb || (z->p[z->c - 1] != 100 && z->p[z->c - 1] != 101)) { z->lb = v_1; return 0; }
        among_var = find_among_b(z, a_7, 7);
        if (!among_var) { z->lb = v_1; return 0; }
        z->bra = z->c;
        z->lb = v_1;
    }
    switch (among_var) {
        case 1:
            {
                int ret = slice_from_s(z, 3, s_4);
                if (ret < 0) return ret;
            }
            break;
        case 2:
            {
                int v_2 = z->l - z->c;
                {
                    int ret = r_LONGV(z);
                    if (ret == 0) goto lab0;
                    if (ret < 0) return ret;
                }
                return 0;
            lab0:
                z->c = z->l - v_2;
            }
            {
                int ret = slice_del(z);
                if (ret < 0) return ret;
            }
            break;
        case 3:
            {
                int v_3 = z->l - z->c;
                {
                    int v_4 = z->l - z->c;
                    {
                        int ret = skip_b_utf8(z->p, z->c, z->lb, 4);
                        if (ret < 0) goto lab2;
                        z->c = ret;
                    }
                    z->c = z->l - v_4;
                }
                if (z->c <= z->lb || (z->p[z->c - 1] != 115 && z->p[z->c - 1] != 116)) among_var = 2; else
                among_var = find_among_b(z, a_6, 5);
                switch (among_var) {
                    case 1:
                        {
                            int ret = slice_from_s(z, 1, s_5);
                            if (ret < 0) return ret;
                        }
                        break;
                    case 2:
                        {
                            int ret = slice_del(z);
                            if (ret < 0) return ret;
                        }
                        break;
                }
                goto lab1;
            lab2:
                z->c = z->l - v_3;
                {
                    int ret = slice_from_s(z, 1, s_6);
                    if (ret < 0) return ret;
                }
            }
        lab1:
            break;
        case 4:
            {
                int v_5 = z->l - z->c;
                if (in_grouping_b_U(z, g_RV, 97, 117, 0)) goto lab4;
                goto lab3;
            lab4:
                z->c = z->l - v_5;
                {
                    int ret = r_LONGV(z);
                    if (ret <= 0) return ret;
                }
            }
        lab3:
            {
                int ret = slice_del(z);
                if (ret < 0) return ret;
            }
            break;
    }
    return 1;
}

static int r_nu(struct SN_env * z) {

    {
        int v_1;
        if (z->c < z->I[0]) return 0;
        v_1 = z->lb; z->lb = z->I[0];
        z->ket = z->c;
        if (z->c - 1 <= z->lb || (z->p[z->c - 1] != 97 && z->p[z->c - 1] != 117)) { z->lb = v_1; return 0; }
        if (!find_among_b(z, a_8, 4)) { z->lb = v_1; return 0; }
        z->bra = z->c;
        z->lb = v_1;
    }
    {
        int ret = slice_del(z);
        if (ret < 0) return ret;
    }
    return 1;
}

static int r_undouble_kpt(struct SN_env * z) {
    int among_var;
    if (in_grouping_b_U(z, g_V1, 97, 252, 0)) return 0;
    if (z->I[0] > z->c) return 0;
    z->ket = z->c;
    if (z->c - 1 <= z->lb || z->p[z->c - 1] >> 5 != 3 || !((1116160 >> (z->p[z->c - 1] & 0x1f)) & 1)) return 0;
    among_var = find_among_b(z, a_9, 3);
    if (!among_var) return 0;
    z->bra = z->c;
    switch (among_var) {
        case 1:
            {
                int ret = slice_from_s(z, 1, s_7);
                if (ret < 0) return ret;
            }
            break;
        case 2:
            {
                int ret = slice_from_s(z, 1, s_8);
                if (ret < 0) return ret;
            }
            break;
        case 3:
            {
                int ret = slice_from_s(z, 1, s_9);
                if (ret < 0) return ret;
            }
            break;
    }
    return 1;
}

static int r_degrees(struct SN_env * z) {
    int among_var;

    {
        int v_1;
        if (z->c < z->I[0]) return 0;
        v_1 = z->lb; z->lb = z->I[0];
        z->ket = z->c;
        if (z->c <= z->lb || z->p[z->c - 1] >> 5 != 3 || !((8706 >> (z->p[z->c - 1] & 0x1f)) & 1)) { z->lb = v_1; return 0; }
        among_var = find_among_b(z, a_10, 3);
        if (!among_var) { z->lb = v_1; return 0; }
        z->bra = z->c;
        z->lb = v_1;
    }
    switch (among_var) {
        case 1:
            if (in_grouping_b_U(z, g_RV, 97, 117, 0)) return 0;
            {
                int ret = slice_del(z);
                if (ret < 0) return ret;
            }
            break;
        case 2:
            {
                int ret = slice_del(z);
                if (ret < 0) return ret;
            }
            break;
    }
    return 1;
}

static int r_substantive(struct SN_env * z) {
    {
        int v_1 = z->l - z->c;
        {
            int ret = r_special_noun_endings(z);
            if (ret < 0) return ret;
        }
        z->c = z->l - v_1;
    }
    {
        int v_2 = z->l - z->c;
        {
            int ret = r_case_ending(z);
            if (ret < 0) return ret;
        }
        z->c = z->l - v_2;
    }
    {
        int v_3 = z->l - z->c;
        {
            int ret = r_plural_three_first_cases(z);
            if (ret < 0) return ret;
        }
        z->c = z->l - v_3;
    }
    {
        int v_4 = z->l - z->c;
        {
            int ret = r_degrees(z);
            if (ret < 0) return ret;
        }
        z->c = z->l - v_4;
    }
    {
        int v_5 = z->l - z->c;
        {
            int ret = r_i_plural(z);
            if (ret < 0) return ret;
        }
        z->c = z->l - v_5;
    }
    {
        int v_6 = z->l - z->c;
        {
            int ret = r_nu(z);
            if (ret < 0) return ret;
        }
        z->c = z->l - v_6;
    }
    return 1;
}

static int r_verb_exceptions(struct SN_env * z) {
    int among_var;
    z->bra = z->c;
    among_var = find_among(z, a_11, 290);
    if (!among_var) return 0;
    z->ket = z->c;
    if (z->c < z->l) return 0;
    switch (among_var) {
        case 1:
            {
                int ret = slice_from_s(z, 3, s_10);
                if (ret < 0) return ret;
            }
            break;
        case 2:
            {
                int ret = slice_from_s(z, 3, s_11);
                if (ret < 0) return ret;
            }
            break;
        case 3:
            {
                int ret = slice_from_s(z, 5, s_12);
                if (ret < 0) return ret;
            }
            break;
        case 4:
            {
                int ret = slice_from_s(z, 5, s_13);
                if (ret < 0) return ret;
            }
            break;
        case 5:
            {
                int ret = slice_from_s(z, 5, s_14);
                if (ret < 0) return ret;
            }
            break;
        case 6:
            {
                int ret = slice_from_s(z, 4, s_15);
                if (ret < 0) return ret;
            }
            break;
        case 7:
            {
                int ret = slice_from_s(z, 3, s_16);
                if (ret < 0) return ret;
            }
            break;
        case 8:
            {
                int ret = slice_from_s(z, 6, s_17);
                if (ret < 0) return ret;
            }
            break;
        case 9:
            {
                int ret = slice_from_s(z, 5, s_18);
                if (ret < 0) return ret;
            }
            break;
        case 10:
            {
                int ret = slice_from_s(z, 3, s_19);
                if (ret < 0) return ret;
            }
            break;
        case 11:
            {
                int ret = slice_from_s(z, 6, s_20);
                if (ret < 0) return ret;
            }
            break;
        case 12:
            {
                int ret = slice_from_s(z, 7, s_21);
                if (ret < 0) return ret;
            }
            break;
        case 13:
            {
                int ret = slice_from_s(z, 7, s_22);
                if (ret < 0) return ret;
            }
            break;
        case 14:
            {
                int ret = slice_from_s(z, 4, s_23);
                if (ret < 0) return ret;
            }
            break;
        case 15:
            {
                int ret = slice_from_s(z, 5, s_24);
                if (ret < 0) return ret;
            }
            break;
        case 16:
            {
                int ret = slice_from_s(z, 4, s_25);
                if (ret < 0) return ret;
            }
            break;
        case 17:
            {
                int ret = slice_from_s(z, 4, s_26);
                if (ret < 0) return ret;
            }
            break;
        case 18:
            {
                int ret = slice_from_s(z, 5, s_27);
                if (ret < 0) return ret;
            }
            break;
    }
    return 1;
}

extern int estonian_UTF_8_stem(struct SN_env * z) {
    {
        int v_1 = z->c;
        {
            int ret = r_verb_exceptions(z);
            if (ret == 0) goto lab0;
            if (ret < 0) return ret;
        }
        return 0;
    lab0:
        z->c = v_1;
    }
    {
        int v_2 = z->c;
        {
            int ret = r_mark_regions(z);
            if (ret < 0) return ret;
        }
        z->c = v_2;
    }
    z->lb = z->c; z->c = z->l;
    {
        int v_3 = z->l - z->c;
        {
            int ret = r_emphasis(z);
            if (ret < 0) return ret;
        }
        z->c = z->l - v_3;
    }
    {
        int v_4 = z->l - z->c;
        {
            int v_5 = z->l - z->c;
            {
                int ret = r_verb(z);
                if (ret == 0) goto lab3;
                if (ret < 0) return ret;
            }
            goto lab2;
        lab3:
            z->c = z->l - v_5;
            {
                int ret = r_substantive(z);
                if (ret < 0) return ret;
            }
        }
    lab2:
        z->c = z->l - v_4;
    }
    {
        int v_6 = z->l - z->c;
        {
            int ret = r_undouble_kpt(z);
            if (ret < 0) return ret;
        }
        z->c = z->l - v_6;
    }
    z->c = z->lb;
    return 1;
}

extern struct SN_env * estonian_UTF_8_create_env(void) { return SN_create_env(0, 1); }

extern void estonian_UTF_8_close_env(struct SN_env * z) { SN_close_env(z, 0); }

