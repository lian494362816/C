#include <string.h>
#include "my_atom.h"
#include "my_error.h"
#include "my_func.h"


#define NELEMS(x) ((sizeof(x) / sizeof((x)[0])))
#define MY_ATOM_BUCKET_MAX 2048

typedef struct atom_s{
	struct atom_s *pstLink;
	S32 s32Len;
	S8  *ps8Str;
}atom_t;

static atom_t *_gpasBuckets[MY_ATOM_BUCKET_MAX];

static U32 _gu32Scatter[] = {
	1804289383, 846930886, 1681692777, 1714636915, 1957747793, 424238335, 719885386, 1649760492, 596516649, 1189641421,
	1025202362, 1350490027, 783368690, 1102520059, 2044897763, 1967513926, 1365180540, 1540383426, 304089172, 1303455736,
	35005211, 521595368, 294702567, 1726956429, 336465782, 861021530, 278722862, 233665123, 2145174067, 468703135,
	1101513929, 1801979802, 1315634022, 635723058, 1369133069, 1125898167, 1059961393, 2089018456, 628175011, 1656478042,
	1131176229, 1653377373, 859484421, 1914544919, 608413784, 756898537, 1734575198, 1973594324, 149798315, 2038664370,
	1129566413, 184803526, 412776091, 1424268980, 1911759956, 749241873, 137806862, 42999170, 982906996, 135497281,
	511702305, 2084420925, 1937477084, 1827336327, 572660336, 1159126505, 805750846, 1632621729, 1100661313, 1433925857,
	1141616124, 84353895, 939819582, 2001100545, 1998898814, 1548233367, 610515434, 1585990364, 1374344043, 760313750,
	1477171087, 356426808, 945117276, 1889947178, 1780695788, 709393584, 491705403, 1918502651, 752392754, 1474612399,
	2053999932, 1264095060, 1411549676, 1843993368, 943947739, 1984210012, 855636226, 1749698586, 1469348094, 1956297539,
	1036140795, 463480570, 2040651434, 1975960378, 317097467, 1892066601, 1376710097, 927612902, 1330573317, 603570492,
	1687926652, 660260756, 959997301, 485560280, 402724286, 593209441, 1194953865, 894429689, 364228444, 1947346619,
	221558440, 270744729, 1063958031, 1633108117, 2114738097, 2007905771, 1469834481, 822890675, 1610120709, 791698927,
	631704567, 498777856, 1255179497, 524872353, 327254586, 1572276965, 269455306, 1703964683, 352406219, 1600028624,
	160051528, 2040332871, 112805732, 1120048829, 378409503, 515530019, 1713258270, 1573363368, 1409959708, 2077486715,
	1373226340, 1631518149, 200747796, 289700723, 1117142618, 168002245, 150122846, 439493451, 990892921, 1760243555,
	1231192379, 1622597488, 111537764, 338888228, 2147469841, 438792350, 1911165193, 269441500, 2142757034, 116087764,
	1869470124, 155324914, 8936987, 1982275856, 1275373743, 387346491, 350322227, 841148365, 1960709859, 1760281936,
	771151432, 1186452551, 1244316437, 971899228, 1476153275, 213975407, 1139901474, 1626276121, 653468858, 2130794395,
	1239036029, 1884661237, 1605908235, 1350573793, 76065818, 1605894428, 1789366143, 1987231011, 1875335928, 1784639529,
	2103318776, 1597322404, 1939964443, 2112255763, 1432114613, 1067854538, 352118606, 1782436840, 1909002904, 165344818,
	1395235128, 532670688, 1351797369, 492067917, 1504569917, 680466996, 706043324, 496987743, 159259470, 1359512183,
	480298490, 1398295499, 1096689772, 2086206725, 601385644, 1172755590, 1544617505, 243268139, 1012502954, 1272469786,
	2027907669, 968338082, 722308542, 1820388464, 933110197, 6939507, 740759355, 1285228804, 1789376348, 502278611,
	1450573622, 1037127828, 1034949299, 654887343, 1529195746, 392035568, 1335354340, 87755422, 889023311, 1494613810,
	1447267605, 1369321801, 745425661, 396473730, 1308044878, 1346811305,
};


S32 my_atom_length(const S8 *ps8Str)
{
    atom_t *pstAtom = NULL;
    S32 s32i = 0;

    for (s32i = 0; s32i < NELEMS(_gpasBuckets); s32i++)
    {
        for (pstAtom = _gpasBuckets[s32i]; pstAtom; pstAtom = pstAtom->pstLink)
        {
            if (pstAtom->ps8Str == ps8Str)
            {
                return pstAtom->s32Len;
            }
        }
    }

    MY_WARING("Not Find:%s\n", ps8Str);

    return MY_FAIL;
}

S8 *my_atom_new(const S8 *ps8Str, S32 s32Len)
{
	U32 u32Head;
	S32 s32i;
	atom_t *pstAtom;

	CHECK_POINTER(ps8Str);

	if (s32Len < 0)
	{
		MY_WARING("s32Len < 0\n");
		return NULL;
	}

   // MY_INFO("s32Len = %d\n", s32Len);

    //散列的查表算法
	for (u32Head = 0; u32Head < s32Len; u32Head ++)
	{
		u32Head = (u32Head << 1) + _gu32Scatter[((U8) ps8Str[u32Head])];
        //MY_INFO("u32Head = %d, s32Len = %d\n", u32Head, s32Len);
	}

	u32Head %= NELEMS(_gpasBuckets);

	for (pstAtom = _gpasBuckets[u32Head]; pstAtom; pstAtom = pstAtom->pstLink)
	{
		if (s32Len == pstAtom->s32Len)
		{
			for (s32i = 0; s32i < s32Len && pstAtom->ps8Str[s32i] == ps8Str[s32i];)
			{
				s32i++;
			}

			if (s32i == s32Len)
			{
				return pstAtom->ps8Str;
			}
		}
	}

	pstAtom = (atom_t *) malloc(sizeof(atom_t) + s32Len +1);
	pstAtom->s32Len = s32Len;
	pstAtom->ps8Str = (S8 *)(pstAtom + 1);
	if (s32Len > 0)
	{
		memcpy(pstAtom->ps8Str, ps8Str, s32Len);
	}
	pstAtom->ps8Str[s32Len] = '0';
	pstAtom->pstLink = _gpasBuckets[u32Head];
	_gpasBuckets[u32Head] = pstAtom;

    return pstAtom->ps8Str;
}

S8 *my_atom_string(const S8 *ps8Str)
{
    CHECK_POINTER(ps8Str);

    return my_atom_new(ps8Str, strlen((const char *)ps8Str));
}

S8 *my_atom_init(S32 s32Num)
{
	S8 as8Str[43];
	S8 *ps8Str = as8Str + sizeof(as8Str);
	U32 u32NumTmp;

	if (s32Num < 0)
	{
		u32NumTmp = - s32Num;
	}
	else
	{
		u32NumTmp = s32Num;
	}

	do {
		*--ps8Str = u32NumTmp % 10 + '0';

	}while((u32NumTmp /= 10) > 0);

	if (s32Num < 0)
	{
		*--ps8Str = '-';
	}

	return my_atom_new(ps8Str, (as8Str + sizeof(as8Str)) - ps8Str);
}

S32 my_atom_print(void)
{
    S32 s32i = 0;
    atom_t *pstAtom = NULL;
    S32 as32Size[NELEMS(_gpasBuckets)] = {0};

    for (s32i = 0; s32i < NELEMS(_gpasBuckets); s32i++)
    {
        for (pstAtom = _gpasBuckets[s32i]; pstAtom; pstAtom = pstAtom->pstLink)
        {
            as32Size[s32i]++;
            printf("[%d], %s\n", s32i, pstAtom->ps8Str);
        }
    }
    printf("==================\n");

    for (s32i = 0; s32i < NELEMS(_gpasBuckets); s32i++)
    {
        if (as32Size[s32i] != 0)
        {
            printf("[%d]:%d\n", s32i, as32Size[s32i]);
        }
    }

    return MY_SUCCESS;
}
