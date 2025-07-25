/* Generated from indonesian.sbl by Snowball 3.0.1 - https://snowballstem.org/ */

#include "../runtime/header.h"

#ifdef __cplusplus
extern "C" {
#endif
extern int indonesian_UTF_8_stem(struct SN_env * z);
#ifdef __cplusplus
}
#endif
static int r_VOWEL(struct SN_env * z);
static int r_SUFFIX_I_OK(struct SN_env * z);
static int r_SUFFIX_AN_OK(struct SN_env * z);
static int r_SUFFIX_KAN_OK(struct SN_env * z);
static int r_KER(struct SN_env * z);
static int r_remove_suffix(struct SN_env * z);
static int r_remove_second_order_prefix(struct SN_env * z);
static int r_remove_first_order_prefix(struct SN_env * z);
static int r_remove_possessive_pronoun(struct SN_env * z);
static int r_remove_particle(struct SN_env * z);
#ifdef __cplusplus
extern "C" {
#endif


extern struct SN_env * indonesian_UTF_8_create_env(void);
extern void indonesian_UTF_8_close_env(struct SN_env * z);


#ifdef __cplusplus
}
#endif
static const symbol s_0_0[3] = { 'k', 'a', 'h' };
static const symbol s_0_1[3] = { 'l', 'a', 'h' };
static const symbol s_0_2[3] = { 'p', 'u', 'n' };
static const struct among a_0[3] = {
{ 3, s_0_0, 0, 1, 0},
{ 3, s_0_1, 0, 1, 0},
{ 3, s_0_2, 0, 1, 0}
};

static const symbol s_1_0[3] = { 'n', 'y', 'a' };
static const symbol s_1_1[2] = { 'k', 'u' };
static const symbol s_1_2[2] = { 'm', 'u' };
static const struct among a_1[3] = {
{ 3, s_1_0, 0, 1, 0},
{ 2, s_1_1, 0, 1, 0},
{ 2, s_1_2, 0, 1, 0}
};

static const symbol s_2_0[1] = { 'i' };
static const symbol s_2_1[2] = { 'a', 'n' };
static const symbol s_2_2[3] = { 'k', 'a', 'n' };
static const struct among a_2[3] = {
{ 1, s_2_0, 0, 1, r_SUFFIX_I_OK},
{ 2, s_2_1, 0, 1, r_SUFFIX_AN_OK},
{ 3, s_2_2, -1, 1, r_SUFFIX_KAN_OK}
};

static const symbol s_3_0[2] = { 'd', 'i' };
static const symbol s_3_1[2] = { 'k', 'e' };
static const symbol s_3_2[2] = { 'm', 'e' };
static const symbol s_3_3[3] = { 'm', 'e', 'm' };
static const symbol s_3_4[3] = { 'm', 'e', 'n' };
static const symbol s_3_5[4] = { 'm', 'e', 'n', 'g' };
static const symbol s_3_6[4] = { 'm', 'e', 'n', 'y' };
static const symbol s_3_7[3] = { 'p', 'e', 'm' };
static const symbol s_3_8[3] = { 'p', 'e', 'n' };
static const symbol s_3_9[4] = { 'p', 'e', 'n', 'g' };
static const symbol s_3_10[4] = { 'p', 'e', 'n', 'y' };
static const symbol s_3_11[3] = { 't', 'e', 'r' };
static const struct among a_3[12] = {
{ 2, s_3_0, 0, 1, 0},
{ 2, s_3_1, 0, 2, 0},
{ 2, s_3_2, 0, 1, 0},
{ 3, s_3_3, -1, 5, 0},
{ 3, s_3_4, -2, 1, 0},
{ 4, s_3_5, -1, 1, 0},
{ 4, s_3_6, -2, 3, r_VOWEL},
{ 3, s_3_7, 0, 6, 0},
{ 3, s_3_8, 0, 2, 0},
{ 4, s_3_9, -1, 2, 0},
{ 4, s_3_10, -2, 4, r_VOWEL},
{ 3, s_3_11, 0, 1, 0}
};

static const symbol s_4_0[2] = { 'b', 'e' };
static const symbol s_4_1[7] = { 'b', 'e', 'l', 'a', 'j', 'a', 'r' };
static const symbol s_4_2[3] = { 'b', 'e', 'r' };
static const symbol s_4_3[2] = { 'p', 'e' };
static const symbol s_4_4[7] = { 'p', 'e', 'l', 'a', 'j', 'a', 'r' };
static const symbol s_4_5[3] = { 'p', 'e', 'r' };
static const struct among a_4[6] = {
{ 2, s_4_0, 0, 3, r_KER},
{ 7, s_4_1, -1, 4, 0},
{ 3, s_4_2, -2, 3, 0},
{ 2, s_4_3, 0, 1, 0},
{ 7, s_4_4, -1, 2, 0},
{ 3, s_4_5, -2, 1, 0}
};

static const unsigned char g_vowel[] = { 17, 65, 16 };

static const symbol s_0[] = { 'e', 'r' };
static const symbol s_1[] = { 's' };
static const symbol s_2[] = { 's' };
static const symbol s_3[] = { 'p' };
static const symbol s_4[] = { 'p' };
static const symbol s_5[] = { 'a', 'j', 'a', 'r' };
static const symbol s_6[] = { 'a', 'j', 'a', 'r' };

static int r_remove_particle(struct SN_env * z) {
    z->ket = z->c;
    if (z->c - 2 <= z->lb || (z->p[z->c - 1] != 104 && z->p[z->c - 1] != 110)) return 0;
    if (!find_among_b(z, a_0, 3)) return 0;
    z->bra = z->c;
    {
        int ret = slice_del(z);
        if (ret < 0) return ret;
    }
    z->I[1] -= 1;
    return 1;
}

static int r_remove_possessive_pronoun(struct SN_env * z) {
    z->ket = z->c;
    if (z->c - 1 <= z->lb || (z->p[z->c - 1] != 97 && z->p[z->c - 1] != 117)) return 0;
    if (!find_among_b(z, a_1, 3)) return 0;
    z->bra = z->c;
    {
        int ret = slice_del(z);
        if (ret < 0) return ret;
    }
    z->I[1] -= 1;
    return 1;
}

static int r_SUFFIX_KAN_OK(struct SN_env * z) {
    if (z->I[0] == 3) return 0;
    if (z->I[0] == 2) return 0;
    return 1;
}

static int r_SUFFIX_AN_OK(struct SN_env * z) {
    return z->I[0] != 1;
}

static int r_SUFFIX_I_OK(struct SN_env * z) {
    if (z->I[0] > 2) return 0;
    {
        int v_1 = z->l - z->c;
        if (z->c <= z->lb || z->p[z->c - 1] != 's') goto lab0;
        z->c--;
        return 0;
    lab0:
        z->c = z->l - v_1;
    }
    return 1;
}

static int r_remove_suffix(struct SN_env * z) {
    z->ket = z->c;
    if (z->c <= z->lb || (z->p[z->c - 1] != 105 && z->p[z->c - 1] != 110)) return 0;
    if (!find_among_b(z, a_2, 3)) return 0;
    z->bra = z->c;
    {
        int ret = slice_del(z);
        if (ret < 0) return ret;
    }
    z->I[1] -= 1;
    return 1;
}

static int r_VOWEL(struct SN_env * z) {
    if (in_grouping_U(z, g_vowel, 97, 117, 0)) return 0;
    return 1;
}

static int r_KER(struct SN_env * z) {
    if (out_grouping_U(z, g_vowel, 97, 117, 0)) return 0;
    if (!(eq_s(z, 2, s_0))) return 0;
    return 1;
}

static int r_remove_first_order_prefix(struct SN_env * z) {
    int among_var;
    z->bra = z->c;
    if (z->c + 1 >= z->l || (z->p[z->c + 1] != 105 && z->p[z->c + 1] != 101)) return 0;
    among_var = find_among(z, a_3, 12);
    if (!among_var) return 0;
    z->ket = z->c;
    switch (among_var) {
        case 1:
            {
                int ret = slice_del(z);
                if (ret < 0) return ret;
            }
            z->I[0] = 1;
            z->I[1] -= 1;
            break;
        case 2:
            {
                int ret = slice_del(z);
                if (ret < 0) return ret;
            }
            z->I[0] = 3;
            z->I[1] -= 1;
            break;
        case 3:
            z->I[0] = 1;
            {
                int ret = slice_from_s(z, 1, s_1);
                if (ret < 0) return ret;
            }
            z->I[1] -= 1;
            break;
        case 4:
            z->I[0] = 3;
            {
                int ret = slice_from_s(z, 1, s_2);
                if (ret < 0) return ret;
            }
            z->I[1] -= 1;
            break;
        case 5:
            z->I[0] = 1;
            z->I[1] -= 1;
            {
                int v_1 = z->c;
                {
                    int v_2 = z->c;
                    if (in_grouping_U(z, g_vowel, 97, 117, 0)) goto lab1;
                    z->c = v_2;
                    {
                        int ret = slice_from_s(z, 1, s_3);
                        if (ret < 0) return ret;
                    }
                }
                goto lab0;
            lab1:
                z->c = v_1;
                {
                    int ret = slice_del(z);
                    if (ret < 0) return ret;
                }
            }
        lab0:
            break;
        case 6:
            z->I[0] = 3;
            z->I[1] -= 1;
            {
                int v_3 = z->c;
                {
                    int v_4 = z->c;
                    if (in_grouping_U(z, g_vowel, 97, 117, 0)) goto lab3;
                    z->c = v_4;
                    {
                        int ret = slice_from_s(z, 1, s_4);
                        if (ret < 0) return ret;
                    }
                }
                goto lab2;
            lab3:
                z->c = v_3;
                {
                    int ret = slice_del(z);
                    if (ret < 0) return ret;
                }
            }
        lab2:
            break;
    }
    return 1;
}

static int r_remove_second_order_prefix(struct SN_env * z) {
    int among_var;
    z->bra = z->c;
    if (z->c + 1 >= z->l || z->p[z->c + 1] != 101) return 0;
    among_var = find_among(z, a_4, 6);
    if (!among_var) return 0;
    z->ket = z->c;
    switch (among_var) {
        case 1:
            {
                int ret = slice_del(z);
                if (ret < 0) return ret;
            }
            z->I[0] = 2;
            z->I[1] -= 1;
            break;
        case 2:
            {
                int ret = slice_from_s(z, 4, s_5);
                if (ret < 0) return ret;
            }
            z->I[1] -= 1;
            break;
        case 3:
            {
                int ret = slice_del(z);
                if (ret < 0) return ret;
            }
            z->I[0] = 4;
            z->I[1] -= 1;
            break;
        case 4:
            {
                int ret = slice_from_s(z, 4, s_6);
                if (ret < 0) return ret;
            }
            z->I[0] = 4;
            z->I[1] -= 1;
            break;
    }
    return 1;
}

extern int indonesian_UTF_8_stem(struct SN_env * z) {
    z->I[1] = 0;
    {
        int v_1 = z->c;
        while (1) {
            {
                int ret = out_grouping_U(z, g_vowel, 97, 117, 1);
                if (ret < 0) goto lab1;
                z->c += ret;
            }
            z->I[1] += 1;
            continue;
        lab1:
            break;
        }
        z->c = v_1;
    }
    if (z->I[1] <= 2) return 0;
    z->I[0] = 0;
    z->lb = z->c; z->c = z->l;
    {
        int v_2 = z->l - z->c;
        {
            int ret = r_remove_particle(z);
            if (ret < 0) return ret;
        }
        z->c = z->l - v_2;
    }
    if (z->I[1] <= 2) return 0;
    {
        int v_3 = z->l - z->c;
        {
            int ret = r_remove_possessive_pronoun(z);
            if (ret < 0) return ret;
        }
        z->c = z->l - v_3;
    }
    z->c = z->lb;
    if (z->I[1] <= 2) return 0;
    {
        int v_4 = z->c;
        {
            int v_5 = z->c;
            {
                int ret = r_remove_first_order_prefix(z);
                if (ret == 0) goto lab3;
                if (ret < 0) return ret;
            }
            {
                int v_6 = z->c;
                {
                    int v_7 = z->c;
                    if (z->I[1] <= 2) goto lab4;
                    z->lb = z->c; z->c = z->l;
                    {
                        int ret = r_remove_suffix(z);
                        if (ret == 0) goto lab4;
                        if (ret < 0) return ret;
                    }
                    z->c = z->lb;
                    z->c = v_7;
                }
                if (z->I[1] <= 2) goto lab4;
                {
                    int ret = r_remove_second_order_prefix(z);
                    if (ret == 0) goto lab4;
                    if (ret < 0) return ret;
                }
            lab4:
                z->c = v_6;
            }
            z->c = v_5;
        }
        goto lab2;
    lab3:
        z->c = v_4;
        {
            int v_8 = z->c;
            {
                int ret = r_remove_second_order_prefix(z);
                if (ret < 0) return ret;
            }
            z->c = v_8;
        }
        {
            int v_9 = z->c;
            if (z->I[1] <= 2) goto lab5;
            z->lb = z->c; z->c = z->l;
            {
                int ret = r_remove_suffix(z);
                if (ret == 0) goto lab5;
                if (ret < 0) return ret;
            }
            z->c = z->lb;
        lab5:
            z->c = v_9;
        }
    }
lab2:
    return 1;
}

extern struct SN_env * indonesian_UTF_8_create_env(void) { return SN_create_env(0, 2); }

extern void indonesian_UTF_8_close_env(struct SN_env * z) { SN_close_env(z, 0); }

