/*    regexp.h
 */

/*
 * Definitions etc. for regexp(3) routines.
 *
 * Caveat:  this is V8 regexp(3) [actually, a reimplementation thereof],
 * not the System V one.
 */


struct regnode {
    U8	flags;
    U8  type;
    U16 next_off;
};

typedef struct regnode regnode;

typedef struct regexp {
	char **startp;
	char **endp;
	regnode *regstclass;
	I32 minlen;		/* mininum possible length of $& */
	I32 prelen;		/* length of precomp */
	U32 nparens;		/* number of parentheses */
	U32 lastparen;		/* last paren matched */
	char *precomp;		/* pre-compilation regular expression */
	char *subbase;		/* saved string so \digit works forever */
	char *subbeg;		/* same, but not responsible for allocation */
	char *subend;		/* end of subbase */
	U16 naughty;		/* how exponential is this pattern? */
	char reganch;		/* Internal use only. */
	char exec_tainted;	/* Tainted information used by regexec? */
        SV *anchored_substr;	/* Substring at fixed position wrt start. */
	I32 anchored_offset;	/* Position of it. */
        SV *float_substr;	/* Substring at variable position wrt start. */
	I32 float_min_offset;	/* Minimal position of it. */
	I32 float_max_offset;	/* Maximal position of it. */
        SV *check_substr;	/* Substring to check before matching. */
        I32 check_offset_min;	/* Offset of the above. */
        I32 check_offset_max;	/* Offset of the above. */
        struct reg_data *data;	/* Additional data. */
	regnode program[1];	/* Unwarranted chumminess with compiler. */
} regexp;

#define ROPT_ANCH		(ROPT_ANCH_BOL|ROPT_ANCH_GPOS)
#define ROPT_ANCH_BOL	 	1
#define ROPT_ANCH_GPOS	 	2
#define ROPT_SKIP		4
#define ROPT_IMPLICIT		8
#define ROPT_CHECK_AT_START	16
#define ROPT_GPOS_SEEN		32
#define ROPT_CHECK_ALL		64

#define REXEC_COPY	1		/* Need to copy the string. */
#define REXEC_CHECKED	2		/* check_substr already checked. */
