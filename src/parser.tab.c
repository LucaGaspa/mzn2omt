/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 11 "parser.y" /* yacc.c:339  */
  
	#include <iostream>
	#include <stdlib.h>
	#include "calc.h"
	void yyerror(const char *);
	int yylex(void);

#line 74 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    END = 0,
    MZN_INTEGER_LITERAL = 258,
    MZN_BOOL_LITERAL = 259,
    MZN_FLOAT_LITERAL = 260,
    MZN_IDENTIFIER = 261,
    MZN_QUOTED_IDENTIFIER = 262,
    MZN_STRING_LITERAL = 263,
    MZN_STRING_QUOTE_START = 264,
    MZN_STRING_QUOTE_MID = 265,
    MZN_STRING_QUOTE_END = 266,
    MZN_TI_IDENTIFIER = 267,
    MZN_DOC_COMMENT = 268,
    MZN_DOC_FILE_COMMENT = 269,
    MZN_VAR = 270,
    MZN_PAR = 271,
    MZN_ABSENT = 272,
    MZN_ANN = 273,
    MZN_ANNOTATION = 274,
    MZN_ANY = 275,
    MZN_ARRAY = 276,
    MZN_BOOL = 277,
    MZN_CASE = 278,
    MZN_CONSTRAINT = 279,
    MZN_DEFAULT = 280,
    MZN_ELSE = 281,
    MZN_ELSEIF = 282,
    MZN_ENDIF = 283,
    MZN_ENUM = 284,
    MZN_FLOAT = 285,
    MZN_FUNCTION = 286,
    MZN_IF = 287,
    MZN_INCLUDE = 288,
    MZN_INFINITY = 289,
    MZN_INT = 290,
    MZN_LET = 291,
    MZN_LIST = 292,
    MZN_MAXIMIZE = 293,
    MZN_MINIMIZE = 294,
    MZN_OF = 295,
    MZN_OPT = 296,
    MZN_SATISFY = 297,
    MZN_OUTPUT = 298,
    MZN_PREDICATE = 299,
    MZN_RECORD = 300,
    MZN_SET = 301,
    MZN_SOLVE = 302,
    MZN_STRING = 303,
    MZN_TEST = 304,
    MZN_THEN = 305,
    MZN_TUPLE = 306,
    MZN_TYPE = 307,
    MZN_UNDERSCORE = 308,
    MZN_VARIANT_RECORD = 309,
    MZN_WHERE = 310,
    MZN_LEFT_BRACKET = 311,
    MZN_LEFT_2D_BRACKET = 312,
    MZN_RIGHT_BRACKET = 313,
    MZN_RIGHT_2D_BRACKET = 314,
    FLATZINC_IDENTIFIER = 315,
    MZN_INVALID_INTEGER_LITERAL = 316,
    MZN_INVALID_FLOAT_LITERAL = 317,
    MZN_UNTERMINATED_STRING = 318,
    MZN_INVALID_NULL = 319,
    MZN_EQUIV = 320,
    MZN_IMPL = 321,
    MZN_RIMPL = 322,
    MZN_OR = 323,
    MZN_XOR = 324,
    MZN_AND = 325,
    MZN_LE = 326,
    MZN_GR = 327,
    MZN_LQ = 328,
    MZN_GQ = 329,
    MZN_EQ = 330,
    MZN_NQ = 331,
    MZN_IN = 332,
    MZN_SUBSET = 333,
    MZN_SUPERSET = 334,
    MZN_UNION = 335,
    MZN_DIFF = 336,
    MZN_SYMDIFF = 337,
    MZN_DOTDOT = 338,
    MZN_PLUS = 339,
    MZN_MINUS = 340,
    MZN_MULT = 341,
    MZN_DIV = 342,
    MZN_IDIV = 343,
    MZN_MOD = 344,
    MZN_INTERSECT = 345,
    MZN_NOT = 346,
    MZN_PLUSPLUS = 347,
    MZN_COLONCOLON = 348,
    PREC_ANNO = 349,
    MZN_EQUIV_QUOTED = 350,
    MZN_IMPL_QUOTED = 351,
    MZN_RIMPL_QUOTED = 352,
    MZN_OR_QUOTED = 353,
    MZN_XOR_QUOTED = 354,
    MZN_AND_QUOTED = 355,
    MZN_LE_QUOTED = 356,
    MZN_GR_QUOTED = 357,
    MZN_LQ_QUOTED = 358,
    MZN_GQ_QUOTED = 359,
    MZN_EQ_QUOTED = 360,
    MZN_NQ_QUOTED = 361,
    MZN_IN_QUOTED = 362,
    MZN_SUBSET_QUOTED = 363,
    MZN_SUPERSET_QUOTED = 364,
    MZN_UNION_QUOTED = 365,
    MZN_DIFF_QUOTED = 366,
    MZN_SYMDIFF_QUOTED = 367,
    MZN_DOTDOT_QUOTED = 368,
    MZN_PLUS_QUOTED = 369,
    MZN_MINUS_QUOTED = 370,
    MZN_MULT_QUOTED = 371,
    MZN_DIV_QUOTED = 372,
    MZN_IDIV_QUOTED = 373,
    MZN_MOD_QUOTED = 374,
    MZN_INTERSECT_QUOTED = 375,
    MZN_NOT_QUOTED = 376,
    MZN_COLONCOLON_QUOTED = 377,
    MZN_PLUSPLUS_QUOTED = 378
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 19 "parser.y" /* yacc.c:355  */

	Expr_node* expr;

#line 243 "parser.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 258 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  151
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4073

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  132
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  268
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  458

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   378

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     126,   127,     2,     2,   128,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   125,   124,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   129,   131,   130,     2,     2,     2,     2,
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
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   137,   137,   139,   141,   144,   146,   148,   150,   152,
     155,   157,   160,   160,   162,   164,   168,   170,   172,   173,
     175,   177,   179,   181,   183,   187,   191,   193,   197,   201,
     205,   207,   209,   213,   217,   219,   223,   225,   229,   231,
     236,   237,   242,   243,   245,   250,   251,   255,   257,   260,
     260,   263,   265,   269,   272,   276,   278,   282,   284,   286,
     290,   292,   294,   296,   298,   300,   302,   307,   308,   312,
     314,   316,   318,   320,   322,   324,   327,   331,   333,   339,
     341,   343,   345,   347,   349,   351,   353,   355,   357,   359,
     361,   363,   365,   367,   369,   371,   373,   379,   381,   383,
     385,   387,   389,   391,   393,   395,   397,   399,   401,   403,
     405,   407,   409,   411,   413,   415,   417,   419,   421,   423,
     425,   427,   429,   431,   433,   435,   437,   439,   441,   443,
     445,   449,   451,   453,   455,   457,   459,   461,   463,   465,
     467,   469,   471,   473,   475,   477,   479,   481,   483,   485,
     487,   489,   491,   493,   495,   497,   499,   501,   505,   507,
     511,   513,   517,   519,   523,   525,   529,   533,   535,   538,
     541,   543,   547,   550,   553,   555,   559,   561,   565,   567,
     569,   571,   575,   577,   579,   583,   585,   589,   593,   597,
     598,   602,   604,   606,   608,   610,   612,   614,   616,   618,
     620,   622,   624,   626,   628,   630,   632,   634,   636,   638,
     640,   642,   644,   646,   648,   650,   652,   654,   658,   660,
     664,   666,   668,   670,   674,   676,   680,   682,   686,   688,
     690,   692,   695,   695,   698,   700,   705,   706,   709,   711,
     715,   717,   719,   721,   723,   725,   727,   729,   731,   733,
     735,   737,   739,   741,   743,   745,   747,   749,   751,   753,
     755,   757,   759,   761,   763,   765,   767,   769,   771
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "\"integer literal\"",
  "\"bool literal\"", "\"float literal\"", "\"identifier\"",
  "\"quoted identifier\"", "\"string literal\"",
  "\"interpolated string start\"", "\"interpolated string middle\"",
  "\"interpolated string end\"", "\"type-inst identifier\"",
  "\"documentation comment\"", "\"file-level documentation comment\"",
  "\"var\"", "\"par\"", "\"<>\"", "\"ann\"", "\"annotation\"", "\"any\"",
  "\"array\"", "\"bool\"", "\"case\"", "\"constraint\"", "\"default\"",
  "\"else\"", "\"elseif\"", "\"endif\"", "\"enum\"", "\"float\"",
  "\"function\"", "\"if\"", "\"include\"", "\"infinity\"", "\"int\"",
  "\"let\"", "\"list\"", "\"maximize\"", "\"minimize\"", "\"of\"",
  "\"opt\"", "\"satisfy\"", "\"output\"", "\"predicate\"", "\"record\"",
  "\"set\"", "\"solve\"", "\"string\"", "\"test\"", "\"then\"",
  "\"tuple\"", "\"type\"", "\"_\"", "\"variant_record\"", "\"where\"",
  "\"[\"", "\"[|\"", "\"]\"", "\"|]\"", "FLATZINC_IDENTIFIER",
  "\"invalid integer literal\"", "\"invalid float literal\"",
  "\"unterminated string\"", "\"null character\"", "\"<->\"", "\"->\"",
  "\"<-\"", "\"\\\\/\"", "\"xor\"", "\"/\\\\\"", "\"<\"", "\">\"",
  "\"<=\"", "\">=\"", "\"=\"", "\"!=\"", "\"in\"", "\"subset\"",
  "\"superset\"", "\"union\"", "\"diff\"", "\"symdiff\"", "\"..\"",
  "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"div\"", "\"mod\"",
  "\"intersect\"", "\"not\"", "\"++\"", "\"::\"", "PREC_ANNO", "\"'<->'\"",
  "\"'->'\"", "\"'<-'\"", "\"'\\\\/'\"", "\"'xor'\"", "\"'/\\\\'\"",
  "\"'<'\"", "\"'>'\"", "\"'<='\"", "\"'>='\"", "\"'='\"", "\"'!='\"",
  "\"'in'\"", "\"'subset'\"", "\"'superset'\"", "\"'union'\"",
  "\"'diff'\"", "\"'symdiff'\"", "\"'..'\"", "\"'+'\"", "\"'-'\"",
  "\"'*'\"", "\"'/'\"", "\"'div'\"", "\"'mod'\"", "\"'intersect'\"",
  "\"'not'\"", "\"'::'\"", "\"'++'\"", "';'", "':'", "'('", "')'", "','",
  "'{'", "'}'", "'|'", "$accept", "model", "item_list", "item_list_head",
  "doc_file_comments", "semi_or_none", "item", "item_tail", "include_item",
  "vardecl_item", "assign_item", "constraint_item", "solve_item",
  "output_item", "predicate_item", "function_item", "annotation_item",
  "operation_item_tail", "params", "params_list", "params_list_head",
  "comma_or_none", "ti_expr_and_id_or_anon", "ti_expr_and_id",
  "ti_expr_list", "ti_expr_list_head", "ti_expr", "base_ti_expr",
  "opt_opt", "base_ti_expr_tail", "expr_list", "expr_list_head",
  "set_expr", "expr", "expr_atom_head", "string_expr", "string_quote_rest",
  "array_access_tail", "set_literal", "set_comp", "comp_tail",
  "generator_list", "generator_list_head", "generator", "id_list",
  "id_list_head", "simple_array_literal", "simple_array_literal_2d",
  "simple_array_literal_3d_list", "simple_array_literal_2d_list",
  "simple_array_comp", "if_then_else_expr", "elseif_list", "quoted_op",
  "quoted_op_call", "call_expr", "comp_or_expr", "let_expr",
  "let_vardecl_item_list", "comma_or_semi", "let_vardecl_item",
  "annotations", "ne_annotations", "id_or_quoted_op", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,    59,    58,    40,    41,    44,   123,
     125,   124
};
# endif

#define YYPACT_NINF -351

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-351)))

#define YYTABLE_NINF -68

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-68)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     501,  -100,  -351,  -351,  -351,   -43,  -351,  3055,  -351,  1658,
    -351,   -15,   -15,  -351,  -351,    22,   -25,  -351,  3055,  -351,
    2039,  3055,    35,  -351,  -351,   -84,     6,  2547,  3055,    44,
     -42,  -351,    46,    -3,  2674,   763,  3182,  3182,  -351,  -351,
    -351,  -351,  -351,  -351,  -351,  -351,  -351,  -351,  -351,  -351,
    -351,  -351,  -351,  -351,  -351,  -351,   -72,  -351,  -351,  -351,
    -351,  -351,  -351,  -351,  -351,  -351,  3055,  1149,    55,  -351,
     -68,  1404,  -351,  -351,  -351,  -351,  -351,  -351,  -351,  -351,
    -351,  -351,  -351,   -42,   -67,  -351,    11,  -351,    57,  -351,
    -351,    -3,    -3,    -3,    -3,    -3,    -3,   -66,  -351,    -3,
    -351,  1531,  3055,  3055,  2801,     3,   -26,  3055,  3055,  3055,
     -65,     8,  3952,  -351,  -351,  -351,  -351,  2293,  2420,   -64,
    2039,  3952,   -62,  3839,  -351,  1785,  2166,  -351,  3952,   -64,
    3217,    -2,   -28,   -64,     3,  -351,     9,   -60,   390,  -351,
     892,  -351,   -36,   -32,    15,    15,  3055,  3529,  -351,   -52,
    3297,  -351,  1277,  -351,  -351,  -351,    -9,    64,    39,  3182,
    3182,  3182,  3182,  3182,  3182,  3182,  3182,  3182,  3182,  3182,
    3182,  3182,  3217,     3,     3,     3,     3,     3,     3,  3055,
       3,  -351,    23,  3952,  -351,    29,   -41,  3055,    18,    18,
      18,  3055,  3055,  -351,  3055,  3055,  3055,  3055,  3055,  3055,
    3055,  3055,  3055,  3055,  3055,  3055,  3055,  3055,  3055,  3055,
    3055,  3055,  3055,  3055,  3055,  3055,  3055,  3055,  3055,  3055,
    3055,  3055,  3055,  3217,    47,  -351,    48,  -351,   636,    19,
      43,   -35,  -351,  3676,  3055,  -351,   -42,   -23,   -95,  -351,
    -351,   -42,  -351,  3055,  3055,  -351,  3217,   -42,  -351,  3055,
    -351,    91,  -351,     0,  -351,     1,  -351,  2928,  3416,    -3,
    -351,    91,  1404,  -351,  3055,   -21,  2547,    20,   234,   234,
     234,   251,   141,   141,    15,    15,    15,    15,   234,    15,
    -351,  3332,  -351,  3055,     7,    76,  3445,  -351,  3952,    42,
    3980,   626,   626,   753,   753,   880,  1009,  1009,  1009,  1009,
    1009,  1009,    37,    37,    37,   268,   268,   268,   477,   167,
     167,    18,    18,    18,    18,   268,    18,  -351,  2547,  2547,
      24,    25,    28,  -351,  -351,   -23,  3055,   113,  1912,  -351,
    -351,  -351,  -351,  -351,  -351,  -351,  -351,  -351,  -351,  -351,
    -351,  -351,  -351,  -351,  -351,  -351,  -351,  -351,  -351,  -351,
    -351,  -351,  -351,  -351,  -351,  -351,  -351,  -351,  -351,   -64,
    3952,    82,   152,  -351,  -351,    86,  1021,    89,  3952,  3952,
    -351,    89,  -351,   107,   112,    40,  -351,    92,    78,  3055,
    3055,  -351,  -351,  3055,     3,    41,  -351,  3952,  1912,  -351,
    -351,  3055,  3952,  3055,  -351,  3055,  -351,  -351,  -351,  -351,
    1912,  -351,  3952,  2166,  -351,   -42,    12,  3055,  -351,  3055,
      93,  -351,  -351,  3055,  -351,  -351,  -351,  3055,    91,  -351,
    3055,   166,  -351,    79,  3558,  -351,    80,  3642,  3671,  3755,
    -351,  -351,    89,  3055,  3055,  3952,  3952,  3055,  3952,  3952,
    -351,  3952,  -351,  3055,  -351,   -42,  -351,  -351,  -351,  -351,
    3868,  3923,  3952,    89,  -351,  3055,  -351,  3952
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,   138,   137,   140,   133,   158,     0,    75,    67,
      10,    67,    67,   142,    73,     0,     0,    70,     0,    71,
      67,     0,     0,   139,    69,     0,     0,    68,     0,     0,
     236,    72,     0,   135,     0,     0,     0,     0,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,     0,   209,   210,   211,
     212,   213,   214,   215,   217,   216,     0,     0,     0,     2,
      12,    67,     5,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,   236,     0,    57,     0,    60,    74,    79,
     141,   143,   145,   147,   149,   151,   153,     0,   221,   156,
     155,    67,     0,     0,     0,   134,   133,     0,     0,     0,
       0,     0,    77,    97,   159,    14,    68,     0,     0,    42,
      67,    29,     0,     0,    25,    67,    67,    61,    33,    42,
       0,     0,   237,    42,   136,   176,     0,    49,    77,   178,
       0,   185,     0,     0,    95,    96,     0,     0,   164,     0,
      77,     1,    13,     4,    11,     6,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   144,   146,   148,   150,   152,   154,     0,
     157,     9,     0,    28,   220,   224,     0,     0,   129,   130,
     128,     0,     0,   160,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,     0,    62,     0,    38,
       0,    49,    55,     0,     0,   229,   236,     0,     0,   228,
      59,   236,   238,     0,     0,    30,     0,   236,   177,    50,
      76,     0,   182,     0,   181,     0,   179,     0,     0,   131,
     165,     0,    67,     7,     0,    53,     0,    94,    81,    82,
      83,    84,    88,    89,    90,    91,    92,    93,    86,    87,
      80,     0,   162,     0,   222,     0,     0,   161,    78,   127,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   121,
     122,   123,   124,   125,   126,   119,   120,    98,     0,     0,
       0,     0,    49,    47,    51,    52,     0,     0,    50,    54,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,    42,
     189,   234,     0,   233,   232,     0,    67,    40,    32,    31,
     239,    40,   174,     0,   167,    49,   170,     0,    49,   183,
       0,   180,   186,     0,   132,     0,     8,    27,    45,    64,
     219,     0,   225,     0,   163,     0,    66,    65,    44,    43,
      50,    46,    39,    67,    56,   236,     0,     0,    53,     0,
       0,   231,   230,     0,    34,    35,   187,     0,    50,   169,
       0,    50,   173,     0,     0,   166,     0,     0,     0,     0,
      48,    58,    40,     0,     0,   235,   226,     0,    41,   168,
     171,   172,   175,   184,    85,   236,   218,   223,   118,    36,
       0,     0,   227,    40,   188,     0,    37,   190
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -351,  -351,  -351,  -351,    59,  -351,   -54,   200,  -351,  -351,
    -351,  -118,  -351,  -351,  -351,  -351,  -351,  -350,  -121,  -213,
    -351,  -216,  -187,  -116,  -351,  -351,   -16,  -120,    30,   -22,
     -33,    13,   279,   -18,   262,  -351,    26,   -19,  -351,  -351,
     -47,  -351,  -351,  -203,  -351,  -351,  -351,  -351,  -351,  -129,
    -351,  -351,  -351,  -351,  -351,  -351,  -351,  -351,  -351,  -351,
    -149,   -81,  -351,  -351
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    68,    69,    70,    71,   153,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,   414,   229,   321,
     322,   250,   323,    83,   230,   231,    84,    85,    86,    87,
     141,   137,    88,   112,   113,    90,   114,   105,    91,    92,
     373,   374,   375,   376,   377,   378,    93,    94,   142,   143,
      95,    96,   406,    97,    98,    99,   186,   100,   238,   366,
     239,   131,   132,   359
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     121,   136,   156,   123,   122,   127,   240,   235,   241,   236,
     128,   253,   247,   102,   134,   329,   138,   155,   192,   193,
     111,   415,   159,   254,   101,   195,   116,   256,   119,   363,
     102,   120,   103,   364,   149,   365,   243,   244,   433,   434,
     245,   117,   118,   124,   195,   125,   126,   181,   147,   150,
     129,   130,   133,   102,   146,   151,   152,   158,   157,   187,
     179,   191,   228,   233,   159,   246,   264,   248,   249,   182,
     265,   185,   173,   174,   175,   176,   177,   178,   260,   266,
     180,   282,   449,   104,   283,   183,   284,   318,   319,   188,
     189,   190,   255,   328,   326,   225,   227,   372,   263,   257,
     104,   327,   362,   456,   232,   388,   401,   171,   172,   237,
     222,   223,   324,   172,   -68,   -68,   -68,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   258,   222,
     223,   379,   380,   393,   394,   223,   194,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   159,   171,
     172,   398,   399,   403,   285,   361,   400,   407,   408,   419,
     367,   281,   422,   409,   413,   416,   371,   417,   418,   420,
     437,   425,   442,   286,   195,   426,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   111,   421,   445,   386,   115,
     443,   262,   325,   430,   385,   440,   360,   412,   287,     0,
       0,     0,     0,     0,   382,   368,   369,   166,   167,   168,
     169,   288,     0,   171,   172,     0,     0,     0,   405,     0,
     384,   159,     0,     0,   389,     0,   387,     0,   411,     0,
     236,   423,     0,   217,   218,   219,   220,     0,   159,   222,
     223,     0,    89,     0,     0,   392,     0,     0,     0,     0,
       0,    89,   324,     0,     0,   195,     0,     0,     0,     0,
       0,     0,    89,   431,   324,     0,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,   396,   397,    89,    89,
       0,     0,     0,     0,     0,     0,     0,     0,   402,     0,
       0,     0,   404,     0,     0,   144,   145,   163,   164,   165,
     166,   167,   168,   169,   432,     0,   171,   172,     0,     0,
       0,     0,     0,    89,   -68,   164,   165,   166,   167,   168,
     169,     0,     0,   171,   172,     0,   382,     0,     0,     0,
     237,   214,   215,   216,   217,   218,   219,   220,     0,     0,
     222,   223,     0,    89,   453,   424,     0,     0,     0,     0,
       0,     0,   325,   427,     0,   428,     0,   429,     0,    89,
      89,     0,    89,     0,   325,     0,     0,    89,    89,   435,
       0,   436,   242,     0,     0,   438,     0,   195,     0,   439,
       0,     0,   441,     0,     0,     0,     0,     0,     0,     0,
     382,     0,     0,     0,    89,   450,   451,     0,     0,   452,
       0,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,   280,     0,     0,   457,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,     0,     0,     0,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,     0,   222,   223,   195,   317,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    -3,     1,     0,     2,     3,     4,     5,   370,     6,
       7,     0,     0,     8,     9,    10,    11,    12,    13,    14,
      15,   251,    16,    17,    89,    18,     0,     0,    89,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,     0,
       0,     0,    27,     0,    28,    29,     0,   -67,    30,    31,
      32,     0,     0,     0,    33,     0,     0,    34,    35,     0,
     -68,   215,   216,   217,   218,   219,   220,     0,     0,   222,
     223,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      89,    89,     0,     0,     0,    36,    37,     0,     0,     0,
      89,     0,     0,     0,     0,     0,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,     0,    65,     0,     0,    66,    89,     0,
      67,     0,     0,   195,     0,     0,     0,   320,     0,     2,
       3,     4,   106,     0,     6,     7,     0,     0,     8,     0,
      89,    11,    12,    13,    14,     0,     0,    16,    17,     0,
       0,     0,    89,     0,     0,    89,    19,     0,    21,     0,
      23,    24,    25,    26,     0,     0,     0,    27,     0,     0,
       0,     0,   -67,     0,    31,     0,     0,     0,     0,    33,
       0,     0,    34,    35,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,     0,   222,   223,
      36,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,    65,
     195,     0,    66,   -45,     0,    67,     2,     3,     4,   106,
       0,     6,     7,     0,     0,     0,     0,     0,     0,     0,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,    23,     0,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    33,     0,     0,    34,
      35,     0,   139,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,     0,   222,   223,   107,   108,     0,
       0,     0,     0,     0,   109,     0,     0,     0,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,   110,    57,    58,    59,
      60,    61,    62,    63,    64,     0,    65,   195,     0,    66,
       0,     0,    67,     0,   140,     2,     3,     4,   106,     0,
       6,     7,     0,     0,     0,     0,     0,     0,     0,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,    23,     0,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,     0,     0,    34,    35,
       0,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,     0,   222,   223,     0,     0,   107,   108,     0,     0,
       0,     0,     0,   109,     0,     0,     0,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,   110,    57,    58,    59,    60,
      61,    62,    63,    64,     0,    65,   195,     0,    66,     0,
       0,    67,     0,   252,     2,     3,     4,   106,     0,     6,
       7,     0,     0,     8,     0,     0,    11,    12,    13,    14,
       0,     0,    16,    17,     0,    18,     0,     0,     0,     0,
       0,    19,     0,    21,     0,    23,    24,    25,    26,     0,
       0,     0,    27,     0,     0,     0,     0,     0,     0,    31,
       0,     0,     0,     0,    33,     0,     0,    34,    35,     0,
     -68,   -68,   -68,   -68,   -68,   -68,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
       0,   222,   223,     0,     0,    36,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,     0,    65,     0,     0,    66,     0,     0,
      67,   410,     2,     3,     4,   106,     0,     6,     7,     0,
       0,     0,     0,     0,     0,     0,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,    23,     0,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,     0,     0,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   107,   108,     0,     0,     0,     0,     0,
     109,     0,     0,     0,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,   110,    57,    58,    59,    60,    61,    62,    63,
      64,     0,    65,     0,     0,    66,     0,     0,    67,   148,
       2,     3,     4,     5,     0,     6,     7,     0,     0,     8,
       9,    10,    11,    12,    13,    14,    15,     0,    16,    17,
       0,    18,     0,     0,     0,     0,     0,    19,    20,    21,
      22,    23,    24,    25,    26,     0,     0,     0,    27,     0,
      28,    29,     0,   -67,    30,    31,    32,     0,     0,     0,
      33,     0,     0,    34,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    36,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,     0,
      65,     0,     0,    66,     0,     0,    67,     2,     3,     4,
       5,     0,     6,     7,     0,     0,     8,     9,   154,    11,
      12,    13,    14,    15,     0,    16,    17,     0,    18,     0,
       0,     0,     0,     0,    19,    20,    21,    22,    23,    24,
      25,    26,     0,     0,     0,    27,     0,    28,    29,     0,
       0,    30,    31,    32,     0,     0,     0,    33,     0,     0,
      34,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    36,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,    65,     0,     0,
      66,     0,     0,    67,     2,     3,     4,     5,     0,     6,
       7,     0,     0,     8,     9,     0,    11,    12,    13,    14,
      15,     0,    16,    17,     0,    18,     0,     0,     0,     0,
       0,    19,    20,    21,    22,    23,    24,    25,    26,     0,
       0,     0,    27,     0,    28,    29,     0,     0,    30,    31,
      32,     0,     0,     0,    33,     0,     0,    34,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,     0,    65,     0,     0,    66,     0,     0,
      67,     2,     3,     4,     5,     0,     6,     7,     0,     0,
       8,     0,     0,    11,    12,    13,    14,    15,     0,    16,
      17,     0,    18,     0,     0,     0,     0,     0,    19,    20,
      21,    22,    23,    24,    25,    26,     0,     0,     0,    27,
       0,    28,    29,     0,     0,    30,    31,    32,     0,     0,
       0,    33,     0,     0,    34,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    36,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,    65,     0,     0,    66,     0,     0,    67,     2,     3,
       4,   106,     0,     6,     7,     0,     0,     8,     0,     0,
      11,    12,    13,    14,     0,     0,    16,    17,     0,    18,
       0,     0,     0,     0,     0,    19,     0,    21,     0,    23,
      24,    25,    26,     0,     0,     0,    27,     0,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,    33,     0,
       0,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    36,
      37,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,     0,    65,     0,
       0,    66,     0,     0,    67,     2,     3,     4,   106,     0,
       6,     7,     0,     0,     8,     0,     0,    11,    12,    13,
      14,     0,     0,    16,    17,     0,     0,     0,     0,     0,
       0,     0,    19,     0,    21,     0,    23,    24,    25,    26,
       0,     0,     0,    27,     0,     0,     0,     0,   -67,     0,
      31,     0,     0,     0,     0,    33,     0,     0,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     0,    65,     0,     0,    66,     0,
       0,    67,     2,     3,     4,   106,     0,     6,     7,     0,
       0,     8,     0,     0,    11,    12,    13,    14,     0,     0,
      16,    17,     0,     0,     0,     0,     0,     0,     0,    19,
       0,    21,     0,    23,    24,    25,    26,     0,     0,     0,
      27,     0,     0,     0,     0,     0,     0,    31,     0,     0,
       0,     0,    33,     0,     0,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,    65,     0,     0,    66,     0,     0,    67,     2,
       3,     4,   106,     0,     6,     7,     0,     0,     8,     0,
       0,    11,    12,    13,    14,     0,     0,     0,    17,     0,
       0,     0,     0,     0,     0,     0,    19,     0,    21,     0,
      23,    24,    25,     0,     0,     0,     0,    27,     0,     0,
       0,     0,     0,     0,    31,     0,     0,     0,     0,    33,
       0,     0,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,    65,
       0,     0,    66,     0,     0,    67,     2,     3,     4,   106,
       0,     6,     7,     0,     0,     8,     0,     0,     0,     0,
      13,    14,     0,     0,     0,    17,     0,     0,     0,     0,
       0,     0,     0,    19,     0,    21,     0,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   224,
       0,    31,     0,     0,     0,     0,    33,     0,     0,    34,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,     0,    65,     0,     0,    66,
       0,     0,    67,     2,     3,     4,   106,     0,     6,     7,
       0,     0,     8,     0,     0,     0,     0,    13,    14,     0,
       0,     0,    17,     0,     0,     0,     0,     0,     0,     0,
      19,     0,    21,     0,    23,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   226,     0,    31,     0,
       0,     0,     0,    33,     0,     0,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    36,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     0,    65,     0,     0,    66,     0,     0,    67,
       2,     3,     4,   106,     0,     6,     7,     0,     0,     8,
       0,     0,     0,     0,    13,    14,     0,     0,     0,    17,
       0,     0,     0,     0,     0,     0,     0,    19,     0,    21,
       0,    23,    24,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    31,     0,     0,     0,     0,
      33,     0,     0,    34,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    36,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,     0,
      65,     0,     0,    66,     0,     0,    67,     2,     3,     4,
     106,     0,     6,     7,     0,     0,     0,     0,     0,     0,
       0,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,    23,     0,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,     0,     0,
      34,    35,   135,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   107,   108,
       0,     0,     0,     0,     0,   109,     0,     0,     0,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,   110,    57,    58,
      59,    60,    61,    62,    63,    64,     0,    65,     0,     0,
      66,     0,     0,    67,     2,     3,     4,   106,     0,     6,
       7,     0,     0,     0,     0,     0,     0,     0,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,    23,     0,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    33,     0,     0,    34,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   107,   108,     0,     0,     0,
       0,     0,   109,     0,     0,     0,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,   110,    57,    58,    59,    60,    61,
      62,    63,    64,     0,    65,     0,     0,    66,   184,     0,
      67,     2,     3,     4,   106,     0,     6,     7,     0,     0,
       0,     0,     0,     0,     0,    13,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,    23,     0,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,     0,     0,    34,    35,     0,   381,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   107,   108,     0,     0,     0,     0,     0,   109,
       0,     0,     0,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,   110,    57,    58,    59,    60,    61,    62,    63,    64,
       0,    65,     0,     0,    66,     0,     0,    67,     2,     3,
       4,   106,     0,     6,     7,     0,     0,     0,     0,     0,
       0,     0,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,     0,    23,
       0,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    33,     0,
       0,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   107,
     108,     0,     0,     0,     0,     0,   109,     0,     0,     0,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,   110,    57,
      58,    59,    60,    61,    62,    63,    64,     0,    65,     0,
       0,    66,     0,     0,    67,     2,     3,     4,   106,     0,
       6,     7,     0,     0,     0,     0,     0,     0,     0,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,    23,     0,    25,     0,
       2,     3,     4,   106,     0,     6,     7,     0,     0,     0,
       0,     0,     0,     0,    13,    33,     0,     0,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,    23,     0,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,    37,     0,     0,
      33,     0,     0,    34,    35,     0,     0,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,   195,    65,     0,     0,    66,     0,
       0,    67,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
       0,    57,    58,    59,    60,    61,    62,    63,    64,   195,
      65,     0,     0,    66,     0,     0,    67,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,     0,   222,
     223,     0,     0,     0,     0,     0,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   195,   222,   223,     0,     0,   261,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   195,     0,     0,     0,     0,     0,     0,   390,
     391,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,     0,   222,   223,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   195,   222,   223,     0,
       0,     0,     0,     0,   383,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   195,     0,     0,     0,     0,
       0,     0,     0,   395,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
       0,   222,   223,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   195,
     222,   223,     0,     0,     0,     0,   259,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   195,     0,
       0,     0,   330,     0,     0,   444,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,     0,   222,   223,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   195,   222,   223,     0,     0,     0,     0,   446,
       0,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   447,   358,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   195,   222,   223,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   195,     0,     0,     0,     0,
       0,     0,   448,     0,     0,     0,     0,     0,     0,   234,
       0,     0,     0,     0,     0,     0,   454,     0,     0,     0,
       0,     0,     0,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     195,   222,   223,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   195,
     222,   223,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   455,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,     0,   222,   223,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,     0,   222,   223,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,     0,   222,   223
};

static const yytype_int16 yycheck[] =
{
      18,    34,    83,    21,    20,    27,   126,   125,   129,   125,
      28,   140,   133,    56,    33,   231,    34,    71,    10,    11,
       7,   371,     7,    59,   124,     7,    41,    59,     6,   124,
      56,    56,    75,   128,    67,   130,    38,    39,    26,    27,
      42,    11,    12,     8,     7,   129,    40,   101,    66,    67,
       6,    93,     6,    56,   126,     0,   124,    46,   125,    56,
     126,   126,   126,   125,     7,    93,    75,    58,   128,   102,
       6,   104,    91,    92,    93,    94,    95,    96,   130,    40,
      99,    58,   432,   126,    55,   103,   127,    40,    40,   107,
     108,   109,   128,   128,    75,   117,   118,     6,   152,   131,
     126,    58,   125,   453,   120,   126,   322,    92,    93,   125,
      92,    93,   228,    93,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,   146,    92,
      93,   131,   131,   126,    58,    93,   128,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,     7,    92,
      93,   127,   127,    40,   187,   236,   128,    75,     6,   375,
     241,   179,   378,    77,    75,    58,   247,    55,   128,    77,
      77,   130,     6,   191,     7,   388,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   192,   128,   127,   262,     9,
     131,   152,   228,   400,   261,   418,   234,   366,   192,    -1,
      -1,    -1,    -1,    -1,   257,   243,   244,    86,    87,    88,
      89,   249,    -1,    92,    93,    -1,    -1,    -1,   359,    -1,
     259,     7,    -1,    -1,   266,    -1,   264,    -1,   366,    -1,
     366,   380,    -1,    86,    87,    88,    89,    -1,     7,    92,
      93,    -1,     0,    -1,    -1,   283,    -1,    -1,    -1,    -1,
      -1,     9,   388,    -1,    -1,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    20,   403,   400,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    -1,    -1,    -1,    -1,   318,   319,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   326,    -1,
      -1,    -1,   328,    -1,    -1,    36,    37,    83,    84,    85,
      86,    87,    88,    89,   405,    -1,    92,    93,    -1,    -1,
      -1,    -1,    -1,    71,    83,    84,    85,    86,    87,    88,
      89,    -1,    -1,    92,    93,    -1,   379,    -1,    -1,    -1,
     366,    83,    84,    85,    86,    87,    88,    89,    -1,    -1,
      92,    93,    -1,   101,   445,   383,    -1,    -1,    -1,    -1,
      -1,    -1,   388,   391,    -1,   393,    -1,   395,    -1,   117,
     118,    -1,   120,    -1,   400,    -1,    -1,   125,   126,   407,
      -1,   409,   130,    -1,    -1,   413,    -1,     7,    -1,   417,
      -1,    -1,   420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     443,    -1,    -1,    -1,   152,   433,   434,    -1,    -1,   437,
      -1,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,   455,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,    -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    -1,    92,    93,     7,   223,    -1,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     0,     1,    -1,     3,     4,     5,     6,   246,     8,
       9,    -1,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,   131,    21,    22,   262,    24,    -1,    -1,   266,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    41,    -1,    43,    44,    -1,    46,    47,    48,
      49,    -1,    -1,    -1,    53,    -1,    -1,    56,    57,    -1,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    92,
      93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     318,   319,    -1,    -1,    -1,    84,    85,    -1,    -1,    -1,
     328,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,   123,    -1,    -1,   126,   366,    -1,
     129,    -1,    -1,     7,    -1,    -1,    -1,     1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    12,    -1,
     388,    15,    16,    17,    18,    -1,    -1,    21,    22,    -1,
      -1,    -1,   400,    -1,    -1,   403,    30,    -1,    32,    -1,
      34,    35,    36,    37,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    -1,    46,    -1,    48,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    56,    57,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    92,    93,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    -1,   123,
       7,    -1,   126,   127,    -1,   129,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    34,    -1,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    56,
      57,    -1,    59,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    92,    93,    84,    85,    -1,
      -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    -1,   123,     7,    -1,   126,
      -1,    -1,   129,    -1,   131,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    -1,    34,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    56,    57,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    -1,    92,    93,    -1,    -1,    84,    85,    -1,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    -1,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    -1,   123,     7,    -1,   126,    -1,
      -1,   129,    -1,   131,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    12,    -1,    -1,    15,    16,    17,    18,
      -1,    -1,    21,    22,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    32,    -1,    34,    35,    36,    37,    -1,
      -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    56,    57,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,    92,    93,    -1,    -1,    84,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,   123,    -1,    -1,   126,    -1,    -1,
     129,   130,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    34,    -1,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    56,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    85,    -1,    -1,    -1,    -1,    -1,
      91,    -1,    -1,    -1,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    -1,   123,    -1,    -1,   126,    -1,    -1,   129,   130,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    21,    22,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    41,    -1,
      43,    44,    -1,    46,    47,    48,    49,    -1,    -1,    -1,
      53,    -1,    -1,    56,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
     123,    -1,    -1,   126,    -1,    -1,   129,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    21,    22,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    41,    -1,    43,    44,    -1,
      -1,    47,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,
      56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,    -1,   123,    -1,    -1,
     126,    -1,    -1,   129,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    12,    13,    -1,    15,    16,    17,    18,
      19,    -1,    21,    22,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    41,    -1,    43,    44,    -1,    -1,    47,    48,
      49,    -1,    -1,    -1,    53,    -1,    -1,    56,    57,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,   123,    -1,    -1,   126,    -1,    -1,
     129,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      12,    -1,    -1,    15,    16,    17,    18,    19,    -1,    21,
      22,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    41,
      -1,    43,    44,    -1,    -1,    47,    48,    49,    -1,    -1,
      -1,    53,    -1,    -1,    56,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,   123,    -1,    -1,   126,    -1,    -1,   129,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    12,    -1,    -1,
      15,    16,    17,    18,    -1,    -1,    21,    22,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    -1,    34,
      35,    36,    37,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    -1,   123,    -1,
      -1,   126,    -1,    -1,   129,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    12,    -1,    -1,    15,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    32,    -1,    34,    35,    36,    37,
      -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,    46,    -1,
      48,    -1,    -1,    -1,    -1,    53,    -1,    -1,    56,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    -1,   123,    -1,    -1,   126,    -1,
      -1,   129,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    12,    -1,    -1,    15,    16,    17,    18,    -1,    -1,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    32,    -1,    34,    35,    36,    37,    -1,    -1,    -1,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    56,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    -1,   123,    -1,    -1,   126,    -1,    -1,   129,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    12,    -1,
      -1,    15,    16,    17,    18,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    -1,
      34,    35,    36,    -1,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    -1,   123,
      -1,    -1,   126,    -1,    -1,   129,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    12,    -1,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    32,    -1,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      -1,    48,    -1,    -1,    -1,    -1,    53,    -1,    -1,    56,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    -1,   123,    -1,    -1,   126,
      -1,    -1,   129,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    32,    -1,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    48,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    56,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    -1,   123,    -1,    -1,   126,    -1,    -1,   129,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,
      -1,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    56,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
     123,    -1,    -1,   126,    -1,    -1,   129,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    34,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      56,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,
      -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,    -1,   123,    -1,    -1,
     126,    -1,    -1,   129,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    34,    -1,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    56,    57,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    85,    -1,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    -1,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,   123,    -1,    -1,   126,   127,    -1,
     129,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    34,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    56,    57,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    85,    -1,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    -1,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,   123,    -1,    -1,   126,    -1,    -1,   129,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    34,
      -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      85,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    -1,   123,    -1,
      -1,   126,    -1,    -1,   129,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    -1,    34,    -1,    36,    -1,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    53,    -1,    -1,    56,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    34,    -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    -1,    -1,
      53,    -1,    -1,    56,    57,    -1,    -1,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,     7,   123,    -1,    -1,   126,    -1,
      -1,   129,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
      -1,   114,   115,   116,   117,   118,   119,   120,   121,     7,
     123,    -1,    -1,   126,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     7,    92,    93,    -1,    -1,   131,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     7,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    92,    93,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,     7,    92,    93,    -1,
      -1,    -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,    92,    93,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,     7,
      92,    93,    -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    -1,
      -1,    -1,     6,    -1,    -1,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,    93,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,     7,    92,    93,    -1,    -1,    -1,    -1,   127,
      -1,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   127,   123,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,     7,    92,    93,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     7,    -1,    -1,    -1,    -1,
      -1,    -1,   127,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
       7,    92,    93,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,     7,
      92,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    92,    93,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,    93,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    -1,    92,    93
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     8,     9,    12,    13,
      14,    15,    16,    17,    18,    19,    21,    22,    24,    30,
      31,    32,    33,    34,    35,    36,    37,    41,    43,    44,
      47,    48,    49,    53,    56,    57,    84,    85,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   123,   126,   129,   133,   134,
     135,   136,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   155,   158,   159,   160,   161,   164,   166,
     167,   170,   171,   178,   179,   182,   183,   185,   186,   187,
     189,   124,    56,    75,   126,   169,     6,    84,    85,    91,
     113,   163,   165,   166,   168,   139,    41,   160,   160,     6,
      56,   165,   158,   165,     8,   129,    40,   161,   165,     6,
      93,   193,   194,     6,   169,    58,   162,   163,   165,    59,
     131,   162,   180,   181,   164,   164,   126,   165,   130,   162,
     165,     0,   124,   137,    14,   138,   193,   125,    46,     7,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    92,    93,   169,   169,   169,   169,   169,   169,   126,
     169,   138,   162,   165,   127,   162,   188,    56,   165,   165,
     165,   126,    10,    11,   128,     7,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    92,    93,    46,   161,    46,   161,   126,   150,
     156,   157,   158,   125,    50,   143,   155,   158,   190,   192,
     159,   150,   166,    38,    39,    42,    93,   150,    58,   128,
     153,   131,   131,   181,    59,   128,    59,   131,   165,   127,
     130,   131,   136,   138,    75,     6,    40,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     166,   165,    58,    55,   127,   162,   165,   168,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   166,    40,    40,
       1,   151,   152,   154,   155,   158,    75,    58,   128,   153,
       6,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   123,   195,
     165,   193,   125,   124,   128,   130,   191,   193,   165,   165,
     166,   193,     6,   172,   173,   174,   175,   176,   177,   131,
     131,    59,   162,   128,   169,   172,   138,   165,   126,   161,
     127,   128,   165,   126,    58,   128,   161,   161,   127,   127,
     128,   153,   165,    40,   158,   150,   184,    75,     6,    77,
     130,   143,   192,    75,   149,   149,    58,    55,   128,   153,
      77,   128,   153,   181,   165,   130,   151,   165,   165,   165,
     154,   159,   193,    26,    27,   165,   165,    77,   165,   165,
     175,   165,     6,   131,   127,   127,   127,   127,   127,   149,
     165,   165,   165,   193,    28,    50,   149,   165
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   132,   133,   134,   134,   135,   135,   135,   135,   135,
     136,   136,   137,   137,   138,   138,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   140,   141,   141,   142,   143,
     144,   144,   144,   145,   146,   146,   147,   147,   148,   148,
     149,   149,   150,   150,   150,   151,   151,   152,   152,   153,
     153,   154,   154,   155,   156,   157,   157,   158,   158,   158,
     159,   159,   159,   159,   159,   159,   159,   160,   160,   161,
     161,   161,   161,   161,   161,   161,   162,   163,   163,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   167,   167,
     168,   168,   169,   169,   170,   170,   171,   172,   172,   173,
     174,   174,   175,   176,   177,   177,   178,   178,   179,   179,
     179,   179,   180,   180,   180,   181,   181,   182,   183,   184,
     184,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   186,   186,
     187,   187,   187,   187,   188,   188,   189,   189,   190,   190,
     190,   190,   191,   191,   192,   192,   193,   193,   194,   194,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     2,     3,     4,     3,
       1,     2,     0,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     4,     3,     2,
       3,     4,     4,     2,     5,     5,     7,     8,     3,     5,
       0,     2,     0,     3,     3,     0,     2,     1,     3,     0,
       1,     1,     1,     3,     2,     1,     3,     1,     6,     3,
       1,     2,     3,     3,     4,     5,     5,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     3,     1,
       3,     3,     3,     3,     3,     6,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     6,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     3,     4,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     1,     2,     1,     2,
       2,     3,     3,     4,     2,     3,     5,     1,     3,     2,
       1,     3,     3,     2,     1,     3,     2,     3,     2,     3,
       4,     3,     2,     3,     5,     1,     3,     5,     8,     0,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     6,     4,
       3,     1,     4,     7,     1,     3,     6,     7,     1,     1,
       3,     3,     1,     1,     2,     4,     0,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 5:
#line 145 "parser.y" /* yacc.c:1646  */
    { }
#line 2430 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 147 "parser.y" /* yacc.c:1646  */
    { }
#line 2436 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 149 "parser.y" /* yacc.c:1646  */
    { }
#line 2442 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 151 "parser.y" /* yacc.c:1646  */
    { }
#line 2448 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 156 "parser.y" /* yacc.c:1646  */
    { }
#line 2454 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 158 "parser.y" /* yacc.c:1646  */
    { }
#line 2460 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 163 "parser.y" /* yacc.c:1646  */
    { }
#line 2466 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 165 "parser.y" /* yacc.c:1646  */
    { }
#line 2472 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 169 "parser.y" /* yacc.c:1646  */
    { }
#line 2478 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 171 "parser.y" /* yacc.c:1646  */
    { }
#line 2484 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 174 "parser.y" /* yacc.c:1646  */
    { }
#line 2490 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 176 "parser.y" /* yacc.c:1646  */
    { }
#line 2496 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 178 "parser.y" /* yacc.c:1646  */
    { }
#line 2502 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 180 "parser.y" /* yacc.c:1646  */
    { }
#line 2508 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 182 "parser.y" /* yacc.c:1646  */
    { }
#line 2514 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 184 "parser.y" /* yacc.c:1646  */
    { }
#line 2520 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 188 "parser.y" /* yacc.c:1646  */
    { }
#line 2526 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 192 "parser.y" /* yacc.c:1646  */
    { }
#line 2532 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 194 "parser.y" /* yacc.c:1646  */
    { }
#line 2538 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 198 "parser.y" /* yacc.c:1646  */
    { }
#line 2544 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 202 "parser.y" /* yacc.c:1646  */
    { }
#line 2550 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 206 "parser.y" /* yacc.c:1646  */
    { }
#line 2556 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 208 "parser.y" /* yacc.c:1646  */
    { }
#line 2562 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 210 "parser.y" /* yacc.c:1646  */
    { }
#line 2568 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 214 "parser.y" /* yacc.c:1646  */
    { }
#line 2574 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 218 "parser.y" /* yacc.c:1646  */
    { }
#line 2580 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 220 "parser.y" /* yacc.c:1646  */
    { }
#line 2586 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 224 "parser.y" /* yacc.c:1646  */
    { }
#line 2592 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 226 "parser.y" /* yacc.c:1646  */
    { }
#line 2598 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 230 "parser.y" /* yacc.c:1646  */
    { }
#line 2604 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 232 "parser.y" /* yacc.c:1646  */
    { }
#line 2610 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 236 "parser.y" /* yacc.c:1646  */
    { }
#line 2616 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 238 "parser.y" /* yacc.c:1646  */
    { }
#line 2622 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 242 "parser.y" /* yacc.c:1646  */
    { }
#line 2628 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 244 "parser.y" /* yacc.c:1646  */
    { }
#line 2634 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 246 "parser.y" /* yacc.c:1646  */
    { }
#line 2640 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 250 "parser.y" /* yacc.c:1646  */
    { }
#line 2646 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 252 "parser.y" /* yacc.c:1646  */
    { }
#line 2652 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 256 "parser.y" /* yacc.c:1646  */
    { }
#line 2658 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 258 "parser.y" /* yacc.c:1646  */
    { }
#line 2664 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 264 "parser.y" /* yacc.c:1646  */
    { }
#line 2670 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 266 "parser.y" /* yacc.c:1646  */
    { }
#line 2676 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 270 "parser.y" /* yacc.c:1646  */
    { }
#line 2682 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 273 "parser.y" /* yacc.c:1646  */
    { }
#line 2688 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 277 "parser.y" /* yacc.c:1646  */
    { }
#line 2694 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 279 "parser.y" /* yacc.c:1646  */
    { }
#line 2700 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 283 "parser.y" /* yacc.c:1646  */
    { }
#line 2706 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 285 "parser.y" /* yacc.c:1646  */
    { }
#line 2712 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 287 "parser.y" /* yacc.c:1646  */
    { }
#line 2718 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 291 "parser.y" /* yacc.c:1646  */
    { }
#line 2724 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 293 "parser.y" /* yacc.c:1646  */
    { }
#line 2730 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 295 "parser.y" /* yacc.c:1646  */
    { }
#line 2736 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 297 "parser.y" /* yacc.c:1646  */
    { }
#line 2742 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 299 "parser.y" /* yacc.c:1646  */
    { }
#line 2748 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 301 "parser.y" /* yacc.c:1646  */
    { }
#line 2754 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 303 "parser.y" /* yacc.c:1646  */
    { }
#line 2760 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 307 "parser.y" /* yacc.c:1646  */
    { }
#line 2766 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 309 "parser.y" /* yacc.c:1646  */
    { }
#line 2772 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 313 "parser.y" /* yacc.c:1646  */
    { }
#line 2778 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 315 "parser.y" /* yacc.c:1646  */
    { }
#line 2784 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 317 "parser.y" /* yacc.c:1646  */
    { }
#line 2790 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 319 "parser.y" /* yacc.c:1646  */
    { }
#line 2796 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 321 "parser.y" /* yacc.c:1646  */
    { }
#line 2802 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 323 "parser.y" /* yacc.c:1646  */
    { }
#line 2808 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 325 "parser.y" /* yacc.c:1646  */
    { }
#line 2814 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 328 "parser.y" /* yacc.c:1646  */
    { }
#line 2820 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 332 "parser.y" /* yacc.c:1646  */
    { }
#line 2826 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 334 "parser.y" /* yacc.c:1646  */
    { }
#line 2832 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 340 "parser.y" /* yacc.c:1646  */
    { }
#line 2838 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 342 "parser.y" /* yacc.c:1646  */
    { }
#line 2844 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 344 "parser.y" /* yacc.c:1646  */
    { }
#line 2850 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 346 "parser.y" /* yacc.c:1646  */
    { }
#line 2856 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 348 "parser.y" /* yacc.c:1646  */
    { }
#line 2862 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 350 "parser.y" /* yacc.c:1646  */
    { }
#line 2868 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 352 "parser.y" /* yacc.c:1646  */
    { }
#line 2874 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 354 "parser.y" /* yacc.c:1646  */
    { }
#line 2880 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 356 "parser.y" /* yacc.c:1646  */
    { }
#line 2886 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 358 "parser.y" /* yacc.c:1646  */
    { }
#line 2892 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 360 "parser.y" /* yacc.c:1646  */
    { }
#line 2898 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 362 "parser.y" /* yacc.c:1646  */
    { }
#line 2904 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 364 "parser.y" /* yacc.c:1646  */
    { }
#line 2910 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 366 "parser.y" /* yacc.c:1646  */
    { }
#line 2916 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 368 "parser.y" /* yacc.c:1646  */
    { }
#line 2922 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 370 "parser.y" /* yacc.c:1646  */
    { }
#line 2928 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 372 "parser.y" /* yacc.c:1646  */
    { }
#line 2934 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 374 "parser.y" /* yacc.c:1646  */
    { }
#line 2940 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 380 "parser.y" /* yacc.c:1646  */
    { }
#line 2946 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 382 "parser.y" /* yacc.c:1646  */
    { }
#line 2952 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 384 "parser.y" /* yacc.c:1646  */
    { }
#line 2958 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 386 "parser.y" /* yacc.c:1646  */
    { }
#line 2964 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 388 "parser.y" /* yacc.c:1646  */
    { }
#line 2970 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 390 "parser.y" /* yacc.c:1646  */
    { }
#line 2976 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 392 "parser.y" /* yacc.c:1646  */
    { }
#line 2982 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 394 "parser.y" /* yacc.c:1646  */
    { }
#line 2988 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 396 "parser.y" /* yacc.c:1646  */
    { }
#line 2994 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 398 "parser.y" /* yacc.c:1646  */
    { }
#line 3000 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 400 "parser.y" /* yacc.c:1646  */
    { }
#line 3006 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 402 "parser.y" /* yacc.c:1646  */
    { }
#line 3012 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 404 "parser.y" /* yacc.c:1646  */
    { }
#line 3018 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 406 "parser.y" /* yacc.c:1646  */
    { }
#line 3024 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 408 "parser.y" /* yacc.c:1646  */
    { }
#line 3030 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 410 "parser.y" /* yacc.c:1646  */
    { }
#line 3036 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 412 "parser.y" /* yacc.c:1646  */
    { }
#line 3042 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 414 "parser.y" /* yacc.c:1646  */
    { }
#line 3048 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 416 "parser.y" /* yacc.c:1646  */
    { }
#line 3054 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 418 "parser.y" /* yacc.c:1646  */
    { }
#line 3060 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 420 "parser.y" /* yacc.c:1646  */
    { }
#line 3066 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 422 "parser.y" /* yacc.c:1646  */
    { }
#line 3072 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 424 "parser.y" /* yacc.c:1646  */
    { }
#line 3078 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 426 "parser.y" /* yacc.c:1646  */
    { }
#line 3084 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 428 "parser.y" /* yacc.c:1646  */
    { }
#line 3090 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 430 "parser.y" /* yacc.c:1646  */
    { }
#line 3096 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 432 "parser.y" /* yacc.c:1646  */
    { }
#line 3102 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 434 "parser.y" /* yacc.c:1646  */
    { }
#line 3108 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 436 "parser.y" /* yacc.c:1646  */
    { }
#line 3114 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 438 "parser.y" /* yacc.c:1646  */
    { }
#line 3120 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 440 "parser.y" /* yacc.c:1646  */
    { }
#line 3126 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 442 "parser.y" /* yacc.c:1646  */
    { }
#line 3132 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 444 "parser.y" /* yacc.c:1646  */
    { }
#line 3138 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 446 "parser.y" /* yacc.c:1646  */
    { }
#line 3144 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 450 "parser.y" /* yacc.c:1646  */
    { }
#line 3150 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 452 "parser.y" /* yacc.c:1646  */
    { }
#line 3156 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 454 "parser.y" /* yacc.c:1646  */
    { }
#line 3162 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 456 "parser.y" /* yacc.c:1646  */
    { }
#line 3168 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 458 "parser.y" /* yacc.c:1646  */
    { }
#line 3174 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 460 "parser.y" /* yacc.c:1646  */
    { }
#line 3180 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 462 "parser.y" /* yacc.c:1646  */
    { }
#line 3186 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 464 "parser.y" /* yacc.c:1646  */
    { }
#line 3192 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 466 "parser.y" /* yacc.c:1646  */
    { }
#line 3198 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 468 "parser.y" /* yacc.c:1646  */
    { }
#line 3204 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 470 "parser.y" /* yacc.c:1646  */
    { }
#line 3210 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 472 "parser.y" /* yacc.c:1646  */
    { }
#line 3216 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 474 "parser.y" /* yacc.c:1646  */
    { }
#line 3222 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 476 "parser.y" /* yacc.c:1646  */
    { }
#line 3228 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 478 "parser.y" /* yacc.c:1646  */
    { }
#line 3234 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 480 "parser.y" /* yacc.c:1646  */
    { }
#line 3240 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 482 "parser.y" /* yacc.c:1646  */
    { }
#line 3246 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 484 "parser.y" /* yacc.c:1646  */
    { }
#line 3252 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 486 "parser.y" /* yacc.c:1646  */
    { }
#line 3258 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 488 "parser.y" /* yacc.c:1646  */
    { }
#line 3264 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 490 "parser.y" /* yacc.c:1646  */
    { }
#line 3270 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 492 "parser.y" /* yacc.c:1646  */
    { }
#line 3276 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 494 "parser.y" /* yacc.c:1646  */
    { }
#line 3282 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 496 "parser.y" /* yacc.c:1646  */
    { }
#line 3288 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 498 "parser.y" /* yacc.c:1646  */
    { }
#line 3294 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 500 "parser.y" /* yacc.c:1646  */
    { }
#line 3300 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 502 "parser.y" /* yacc.c:1646  */
    { }
#line 3306 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 506 "parser.y" /* yacc.c:1646  */
    { }
#line 3312 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 508 "parser.y" /* yacc.c:1646  */
    { }
#line 3318 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 512 "parser.y" /* yacc.c:1646  */
    { }
#line 3324 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 514 "parser.y" /* yacc.c:1646  */
    { }
#line 3330 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 518 "parser.y" /* yacc.c:1646  */
    { }
#line 3336 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 520 "parser.y" /* yacc.c:1646  */
    { }
#line 3342 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 524 "parser.y" /* yacc.c:1646  */
    { }
#line 3348 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 526 "parser.y" /* yacc.c:1646  */
    { }
#line 3354 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 530 "parser.y" /* yacc.c:1646  */
    { }
#line 3360 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 534 "parser.y" /* yacc.c:1646  */
    { }
#line 3366 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 536 "parser.y" /* yacc.c:1646  */
    { }
#line 3372 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 542 "parser.y" /* yacc.c:1646  */
    { }
#line 3378 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 544 "parser.y" /* yacc.c:1646  */
    { }
#line 3384 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 548 "parser.y" /* yacc.c:1646  */
    { }
#line 3390 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 554 "parser.y" /* yacc.c:1646  */
    { }
#line 3396 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 556 "parser.y" /* yacc.c:1646  */
    { }
#line 3402 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 560 "parser.y" /* yacc.c:1646  */
    { }
#line 3408 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 562 "parser.y" /* yacc.c:1646  */
    { }
#line 3414 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 566 "parser.y" /* yacc.c:1646  */
    { }
#line 3420 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 568 "parser.y" /* yacc.c:1646  */
    { }
#line 3426 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 570 "parser.y" /* yacc.c:1646  */
    { }
#line 3432 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 572 "parser.y" /* yacc.c:1646  */
    { }
#line 3438 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 576 "parser.y" /* yacc.c:1646  */
    { }
#line 3444 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 578 "parser.y" /* yacc.c:1646  */
    { }
#line 3450 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 580 "parser.y" /* yacc.c:1646  */
    { }
#line 3456 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 584 "parser.y" /* yacc.c:1646  */
    { }
#line 3462 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 586 "parser.y" /* yacc.c:1646  */
    { }
#line 3468 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 590 "parser.y" /* yacc.c:1646  */
    { }
#line 3474 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 594 "parser.y" /* yacc.c:1646  */
    { }
#line 3480 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 597 "parser.y" /* yacc.c:1646  */
    { }
#line 3486 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 599 "parser.y" /* yacc.c:1646  */
    { }
#line 3492 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 603 "parser.y" /* yacc.c:1646  */
    { }
#line 3498 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 605 "parser.y" /* yacc.c:1646  */
    { }
#line 3504 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 607 "parser.y" /* yacc.c:1646  */
    { }
#line 3510 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 609 "parser.y" /* yacc.c:1646  */
    { }
#line 3516 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 611 "parser.y" /* yacc.c:1646  */
    { }
#line 3522 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 613 "parser.y" /* yacc.c:1646  */
    { }
#line 3528 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 615 "parser.y" /* yacc.c:1646  */
    { }
#line 3534 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 617 "parser.y" /* yacc.c:1646  */
    { }
#line 3540 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 619 "parser.y" /* yacc.c:1646  */
    { }
#line 3546 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 621 "parser.y" /* yacc.c:1646  */
    { }
#line 3552 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 623 "parser.y" /* yacc.c:1646  */
    { }
#line 3558 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 625 "parser.y" /* yacc.c:1646  */
    { }
#line 3564 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 627 "parser.y" /* yacc.c:1646  */
    { }
#line 3570 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 629 "parser.y" /* yacc.c:1646  */
    { }
#line 3576 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 631 "parser.y" /* yacc.c:1646  */
    { }
#line 3582 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 633 "parser.y" /* yacc.c:1646  */
    { }
#line 3588 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 635 "parser.y" /* yacc.c:1646  */
    { }
#line 3594 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 637 "parser.y" /* yacc.c:1646  */
    { }
#line 3600 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 639 "parser.y" /* yacc.c:1646  */
    { }
#line 3606 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 641 "parser.y" /* yacc.c:1646  */
    { }
#line 3612 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 643 "parser.y" /* yacc.c:1646  */
    { }
#line 3618 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 645 "parser.y" /* yacc.c:1646  */
    { }
#line 3624 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 647 "parser.y" /* yacc.c:1646  */
    { }
#line 3630 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 649 "parser.y" /* yacc.c:1646  */
    { }
#line 3636 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 651 "parser.y" /* yacc.c:1646  */
    { }
#line 3642 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 653 "parser.y" /* yacc.c:1646  */
    { }
#line 3648 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 655 "parser.y" /* yacc.c:1646  */
    { }
#line 3654 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 659 "parser.y" /* yacc.c:1646  */
    { }
#line 3660 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 661 "parser.y" /* yacc.c:1646  */
    { }
#line 3666 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 665 "parser.y" /* yacc.c:1646  */
    { }
#line 3672 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 667 "parser.y" /* yacc.c:1646  */
    { }
#line 3678 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 669 "parser.y" /* yacc.c:1646  */
    { }
#line 3684 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 671 "parser.y" /* yacc.c:1646  */
    { }
#line 3690 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 675 "parser.y" /* yacc.c:1646  */
    { }
#line 3696 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 677 "parser.y" /* yacc.c:1646  */
    { }
#line 3702 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 681 "parser.y" /* yacc.c:1646  */
    { }
#line 3708 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 683 "parser.y" /* yacc.c:1646  */
    { }
#line 3714 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 687 "parser.y" /* yacc.c:1646  */
    { }
#line 3720 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 689 "parser.y" /* yacc.c:1646  */
    { }
#line 3726 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 691 "parser.y" /* yacc.c:1646  */
    { }
#line 3732 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 693 "parser.y" /* yacc.c:1646  */
    { }
#line 3738 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 699 "parser.y" /* yacc.c:1646  */
    { }
#line 3744 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 701 "parser.y" /* yacc.c:1646  */
    { }
#line 3750 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 705 "parser.y" /* yacc.c:1646  */
    { }
#line 3756 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 710 "parser.y" /* yacc.c:1646  */
    { }
#line 3762 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 712 "parser.y" /* yacc.c:1646  */
    { }
#line 3768 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 716 "parser.y" /* yacc.c:1646  */
    { }
#line 3774 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 718 "parser.y" /* yacc.c:1646  */
    { }
#line 3780 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 720 "parser.y" /* yacc.c:1646  */
    { }
#line 3786 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 722 "parser.y" /* yacc.c:1646  */
    { }
#line 3792 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 724 "parser.y" /* yacc.c:1646  */
    { }
#line 3798 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 726 "parser.y" /* yacc.c:1646  */
    { }
#line 3804 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 728 "parser.y" /* yacc.c:1646  */
    { }
#line 3810 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 730 "parser.y" /* yacc.c:1646  */
    { }
#line 3816 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 732 "parser.y" /* yacc.c:1646  */
    { }
#line 3822 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 734 "parser.y" /* yacc.c:1646  */
    { }
#line 3828 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 736 "parser.y" /* yacc.c:1646  */
    { }
#line 3834 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 738 "parser.y" /* yacc.c:1646  */
    { }
#line 3840 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 740 "parser.y" /* yacc.c:1646  */
    { }
#line 3846 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 742 "parser.y" /* yacc.c:1646  */
    { }
#line 3852 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 744 "parser.y" /* yacc.c:1646  */
    { }
#line 3858 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 746 "parser.y" /* yacc.c:1646  */
    { }
#line 3864 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 256:
#line 748 "parser.y" /* yacc.c:1646  */
    { }
#line 3870 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 257:
#line 750 "parser.y" /* yacc.c:1646  */
    { }
#line 3876 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 258:
#line 752 "parser.y" /* yacc.c:1646  */
    { }
#line 3882 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 259:
#line 754 "parser.y" /* yacc.c:1646  */
    { }
#line 3888 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 260:
#line 756 "parser.y" /* yacc.c:1646  */
    { }
#line 3894 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 758 "parser.y" /* yacc.c:1646  */
    { }
#line 3900 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 262:
#line 760 "parser.y" /* yacc.c:1646  */
    { }
#line 3906 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 263:
#line 762 "parser.y" /* yacc.c:1646  */
    { }
#line 3912 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 264:
#line 764 "parser.y" /* yacc.c:1646  */
    { }
#line 3918 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 265:
#line 766 "parser.y" /* yacc.c:1646  */
    { }
#line 3924 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 266:
#line 768 "parser.y" /* yacc.c:1646  */
    { }
#line 3930 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 267:
#line 770 "parser.y" /* yacc.c:1646  */
    { }
#line 3936 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 268:
#line 772 "parser.y" /* yacc.c:1646  */
    { }
#line 3942 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 3946 "parser.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 775 "parser.y" /* yacc.c:1906  */



int main() {
	yyparse(); // yyparse automatically calls yylex to obtain tokens
	return 0;
}
