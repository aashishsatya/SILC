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
#line 1 "expl.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdlib.h>

	#include "y.tab.h"
	#include "codegenfunc.c"
	#include "typetables.c"

	int yylex(void);
	extern FILE *yyin;
	extern int yylineno;
	extern char *yytext;
	extern int line_no;

  //int *var[26];
	int variable_type;	// this will store the type of the variable that is being processed

#line 84 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    PLUS = 258,
    MUL = 259,
    ASGN = 260,
    READ = 261,
    WRITE = 262,
    LT = 263,
    GT = 264,
    EQ = 265,
    IF = 266,
    WHILE = 267,
    DO = 268,
    ENDWHILE = 269,
    ENDIF = 270,
    PARENS = 271,
    THEN = 272,
    ID = 273,
    NUM = 274,
    DIV = 275,
    MINUS = 276,
    DECL = 277,
    ENDDECL = 278,
    BOOL = 279,
    INT = 280,
    ENDOFFILE = 281,
    BEGINNING = 282,
    END = 283,
    MAIN = 284,
    RETURN = 285,
    LE = 286,
    GE = 287,
    TYPEDEF = 288
  };
#endif
/* Tokens.  */
#define PLUS 258
#define MUL 259
#define ASGN 260
#define READ 261
#define WRITE 262
#define LT 263
#define GT 264
#define EQ 265
#define IF 266
#define WHILE 267
#define DO 268
#define ENDWHILE 269
#define ENDIF 270
#define PARENS 271
#define THEN 272
#define ID 273
#define NUM 274
#define DIV 275
#define MINUS 276
#define DECL 277
#define ENDDECL 278
#define BOOL 279
#define INT 280
#define ENDOFFILE 281
#define BEGINNING 282
#define END 283
#define MAIN 284
#define RETURN 285
#define LE 286
#define GE 287
#define TYPEDEF 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 19 "expl.y" /* yacc.c:355  */

	int int_val;
	struct  Tnode *tnode_ptr;

#line 195 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 210 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   315

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  155

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,     2,
      38,    39,     2,     2,    37,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    42,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    35,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    72,    72,   108,   134,   135,   138,   220,   224,   228,
     233,   244,   254,   263,   274,   324,   326,   327,   330,   332,
     338,   344,   351,   352,   357,   359,   360,   365,   366,   369,
     371,   376,   392,   397,   415,   428,   438,   452,   471,   483,
     507,   515,   523,   531,   539,   543,   547,   550,   553,   555,
     557,   559,   561,   563,   572,   596,   630,   634,   638,   642,
     646
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PLUS", "MUL", "ASGN", "READ", "WRITE",
  "LT", "GT", "EQ", "IF", "WHILE", "DO", "ENDWHILE", "ENDIF", "PARENS",
  "THEN", "ID", "NUM", "DIV", "MINUS", "DECL", "ENDDECL", "BOOL", "INT",
  "ENDOFFILE", "BEGINNING", "END", "MAIN", "RETURN", "LE", "GE", "TYPEDEF",
  "'{'", "'}'", "';'", "','", "'('", "')'", "'&'", "'['", "']'", "$accept",
  "start", "userDataTypeDecln", "funcDefnList", "funcDefn", "ArgList",
  "vbl_declns", "MainBlock", "localDeclarations", "local_dec_list",
  "local_dec", "local_id_list", "funcBody", "slist", "declarations",
  "dec_list", "type", "dec", "id_list", "stmt", "ArgListFunctionCall",
  "expr", YY_NULLPTR
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
     285,   286,   287,   288,   123,   125,    59,    44,    40,    41,
      38,    91,    93
};
# endif

#define YYPACT_NINF -78

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-78)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -12,    27,    18,   -78,   -78,   -78,     2,    17,    27,   -78,
     -78,   -78,    51,    92,   -78,    27,    27,    40,   -78,    48,
     -78,    78,    35,    49,    -1,    32,    55,   -78,    69,    73,
     -78,   -78,    82,    94,   -78,    27,   120,    27,    76,   -78,
      27,     4,    97,    71,   101,   107,   -78,   -78,   124,   -78,
     -78,   109,   122,   -78,   122,    27,   123,   125,   128,    27,
     129,    43,    43,   130,   -78,   -78,   -78,    96,   131,   132,
     135,   138,     7,    72,   255,   -78,   258,   -78,   -78,   148,
     149,    72,    72,    72,    72,    72,    61,   -78,    72,   188,
     133,   -78,   -78,   -78,    62,   114,   117,   151,   191,    37,
      72,    72,   154,    72,    72,    72,    72,    72,    72,    72,
      72,    72,   -78,   -78,   141,    72,   142,   162,   167,   -78,
     176,    75,   225,    74,   -78,   240,     5,    11,    11,    11,
       5,   240,    11,    11,   -78,    77,   -78,    43,    43,    72,
      72,   -78,   -78,   145,   283,   285,   222,   225,   152,   153,
     166,   -78,   -78,   -78,   -78
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,    28,    27,     0,     0,    26,     1,
       5,    24,    32,     0,    25,     0,     9,     0,    29,     0,
       4,     0,     0,     0,     0,     0,    30,     2,     0,     0,
      35,    12,     0,     8,    33,     9,     0,     9,     0,    13,
       9,     0,     0,     0,     0,     0,     7,    10,     0,    34,
      31,     0,     0,    11,     0,     0,     0,     0,     0,    17,
       0,     0,     0,     0,    15,    16,    20,     0,     0,     0,
       0,     0,     0,     0,     0,    23,     0,     6,    18,     0,
       0,     0,     0,     0,     0,     0,    53,    52,     0,     0,
       0,    22,    21,    19,     0,     0,     0,     0,     0,     0,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    43,    14,     0,     0,     0,     0,     0,    36,
       0,     0,    45,     0,    51,    47,    48,    56,    57,    58,
      50,    49,    59,    60,    38,     0,    40,     0,     0,     0,
       0,    55,    54,     0,     0,     0,     0,    44,     0,     0,
       0,    37,    39,    41,    42
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -78,   -78,   -78,   -78,   -78,    30,   -78,   -78,   150,   144,
     -78,   -78,   -78,   -62,   -78,   179,     1,   -78,   -78,   -73,
     -78,   -77
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    10,    15,    20,    23,    33,    21,    56,    58,
      59,    67,    63,    74,     3,     6,    24,     8,    13,    75,
     121,    89
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      76,    91,     7,    91,    95,    96,    97,    98,    99,     7,
       1,   102,    84,   105,   106,   107,    22,    31,     9,    -1,
      -1,    -1,    47,   122,   123,    11,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    12,   110,   111,   135,    32,
     103,   104,    -1,    -1,    48,   105,   106,   107,    85,    68,
      69,     4,     5,    28,    70,    71,    60,   108,   109,    25,
      60,    72,   146,   147,    29,    42,    26,    44,   110,   111,
      46,    91,    91,    73,    34,   144,   145,   103,   104,   120,
     103,   104,   105,   106,   107,   105,   106,   107,    30,    16,
      86,    87,    17,    35,   108,   109,    36,   108,   109,   100,
      39,   114,   101,   115,    27,   110,   111,    37,   110,   111,
      88,    38,   140,    50,   141,    45,   142,   103,   104,   143,
     103,   104,   105,   106,   107,   105,   106,   107,    18,    19,
      40,    41,    78,    79,   108,   109,    49,   108,   109,    43,
      51,    52,    53,    54,    55,   110,   111,    66,   110,   111,
      61,    64,    62,   116,   103,   104,   117,   103,   104,   105,
     106,   107,   105,   106,   107,    77,    93,    94,   113,    80,
      81,   108,   109,    82,   108,   109,    83,   134,   136,   137,
     138,   139,   110,   111,   148,   110,   111,    14,   152,   153,
     118,   103,   104,   124,   103,   104,   105,   106,   107,   105,
     106,   107,   154,    65,    57,     0,     0,     0,   108,   109,
       0,   108,   109,     0,     0,     0,     0,     0,     0,   110,
     111,     0,   110,   111,   112,   103,   104,   119,   103,   104,
     105,   106,   107,   105,   106,   107,     0,     0,     0,     0,
       0,     0,   108,   109,   104,   108,   109,     0,   105,   106,
     107,     0,     0,   110,   111,     0,   110,   111,   151,     0,
     108,    68,    69,     0,    68,    69,    70,    71,     0,    70,
      71,   110,   111,    72,     0,     0,    72,     0,     0,     0,
       0,     0,     0,    90,     0,    73,    92,     0,    73,    68,
      69,    68,    69,     0,    70,    71,    70,    71,   149,   150,
       0,    72,     0,    72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,     0,    73
};

static const yytype_int16 yycheck[] =
{
      62,    74,     1,    76,    81,    82,    83,    84,    85,     8,
      22,    88,     5,     8,     9,    10,    15,    18,     0,     8,
       9,    10,    18,   100,   101,    23,   103,   104,   105,   106,
     107,   108,   109,   110,   111,    18,    31,    32,   115,    40,
       3,     4,    31,    32,    40,     8,     9,    10,    41,     6,
       7,    24,    25,    18,    11,    12,    55,    20,    21,    19,
      59,    18,   139,   140,    29,    35,    18,    37,    31,    32,
      40,   144,   145,    30,    42,   137,   138,     3,     4,    42,
       3,     4,     8,     9,    10,     8,     9,    10,    39,    38,
      18,    19,    41,    38,    20,    21,    41,    20,    21,    38,
      18,    39,    41,    41,    26,    31,    32,    38,    31,    32,
      38,    38,    37,    42,    39,    39,    42,     3,     4,    42,
       3,     4,     8,     9,    10,     8,     9,    10,    36,    37,
      36,    37,    36,    37,    20,    21,    39,    20,    21,    19,
      39,    34,    18,    34,    22,    31,    32,    18,    31,    32,
      27,    23,    27,    39,     3,     4,    39,     3,     4,     8,
       9,    10,     8,     9,    10,    35,    18,    18,    35,    38,
      38,    20,    21,    38,    20,    21,    38,    36,    36,    17,
      13,     5,    31,    32,    39,    31,    32,     8,    36,    36,
      39,     3,     4,    39,     3,     4,     8,     9,    10,     8,
       9,    10,    36,    59,    54,    -1,    -1,    -1,    20,    21,
      -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    31,    32,    36,     3,     4,    36,     3,     4,
       8,     9,    10,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,     4,    20,    21,    -1,     8,     9,
      10,    -1,    -1,    31,    32,    -1,    31,    32,    36,    -1,
      20,     6,     7,    -1,     6,     7,    11,    12,    -1,    11,
      12,    31,    32,    18,    -1,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    30,    28,    -1,    30,     6,
       7,     6,     7,    -1,    11,    12,    11,    12,    15,    14,
      -1,    18,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    22,    44,    57,    24,    25,    58,    59,    60,     0,
      45,    23,    18,    61,    58,    46,    38,    41,    36,    37,
      47,    50,    59,    48,    59,    19,    18,    26,    18,    29,
      39,    18,    40,    49,    42,    38,    41,    38,    38,    18,
      36,    37,    48,    19,    48,    39,    48,    18,    40,    39,
      42,    39,    34,    18,    34,    22,    51,    51,    52,    53,
      59,    27,    27,    55,    23,    52,    18,    54,     6,     7,
      11,    12,    18,    30,    56,    62,    56,    35,    36,    37,
      38,    38,    38,    38,     5,    41,    18,    19,    38,    64,
      28,    62,    28,    18,    18,    64,    64,    64,    64,    64,
      38,    41,    64,     3,     4,     8,     9,    10,    20,    21,
      31,    32,    36,    35,    39,    41,    39,    39,    39,    36,
      42,    63,    64,    64,    39,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    36,    64,    36,    17,    13,     5,
      37,    39,    42,    42,    56,    56,    64,    64,    39,    15,
      14,    36,    36,    36,    36
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    46,    46,    47,    48,    48,    48,
      49,    49,    49,    49,    50,    51,    52,    52,    53,    54,
      54,    55,    56,    56,    57,    58,    58,    59,    59,    60,
      61,    61,    61,    61,    61,    61,    62,    62,    62,    62,
      62,    62,    62,    62,    63,    63,    63,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     0,     2,     0,     9,     4,     2,     0,
       3,     4,     1,     2,    10,     3,     2,     1,     3,     3,
       1,     3,     2,     1,     3,     2,     1,     1,     1,     3,
       3,     6,     1,     4,     6,     4,     4,     7,     5,     8,
       5,     8,     8,     3,     3,     1,     0,     3,     3,     3,
       3,     3,     1,     1,     4,     4,     3,     3,     3,     3,
       3
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
        case 2:
#line 72 "expl.y" /* yacc.c:1646  */
    {

		if (no_defined_functions != no_declared_functions) {
			printf("All declared functions have not been defined, exiting.\n");
			exit(0);
		}

		printf("In start...\n");

		//fprintf(fp, "START\n");
		//code_gen($3);	// generate the intermediate code
		//fprintf(fp, "HALT\n");

		fclose(fp);

		// deallocate memory used in symbol table

		struct Gsymbol *temp = global_symbol_table_start;
		while (temp != NULL) {
			global_symbol_table_start = global_symbol_table_start -> NEXT;
			free(temp);
			temp = global_symbol_table_start;
		}

		exit(1);
	}
#line 1444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 108 "expl.y" /* yacc.c:1646  */
    {}
#line 1450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 134 "expl.y" /* yacc.c:1646  */
    {code_gen((yyvsp[0].tnode_ptr));}
#line 1456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 135 "expl.y" /* yacc.c:1646  */
    {}
#line 1462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 138 "expl.y" /* yacc.c:1646  */
    {

		printf("Processing function %s...\n", (yyvsp[-7].tnode_ptr) -> NAME);

		// check if the function name has been declared earlier

		// check if the number of arguments and their types are correct
		struct Gsymbol *fn_declaration = Glookup((yyvsp[-7].tnode_ptr) -> NAME);
		fn_declaration -> local_sym_table = current_local_symbol_table;
		// fn_declaration -> ARGLIST will contain the arguments of the function
		// this will have been declared by the 'declarations' section
		struct ArgStruct *fn_decln_arglist = fn_declaration -> ARGLIST;
		struct ArgStruct *fn_defn_arglist = current_arg_list;	// hope the names are clear
		struct ArgStruct *temp_decln_arglist = fn_decln_arglist;
		struct ArgStruct *temp_defn_arglist = fn_defn_arglist;

		current_arg_list = NULL;	// again, bug if not added
		current_arg_binding = 3;
		// this will reset the argument list of functions so that new functions when
		// parsed can simply set this variable (see below rule) and continue

		while (temp_decln_arglist != NULL && temp_defn_arglist != NULL) {
			printf("Stored parameter of name %s\n", temp_decln_arglist -> NAME);
			printf("Its argument binding is %d\n", temp_decln_arglist -> ARG_SIM_BINDING);
			if (strcmp(temp_decln_arglist -> NAME, temp_defn_arglist -> NAME) != 0) {
				printf("Arguments in declaration and definition of function %s are not the same type, exiting.\n", (yyvsp[-7].tnode_ptr) -> NAME);
				exit(0);
			}
			if (temp_decln_arglist -> TYPE  != temp_defn_arglist -> TYPE) {
				printf("Arguments in declaration and definition of function %s are not the same type, exiting.\n", (yyvsp[-7].tnode_ptr) -> NAME);
				exit(0);
			}
			temp_decln_arglist = temp_decln_arglist -> NEXT;
			temp_defn_arglist = temp_defn_arglist -> NEXT;
		}

		if (temp_defn_arglist != NULL || temp_decln_arglist != NULL) {
			printf("Incorrect number of arguments in declaration and definition of function %s, exiting.\n", (yyvsp[-7].tnode_ptr) -> NAME);
			exit(0);
		}

		if (no_return_statements == 0) {
			printf("A return statement is required for function %s, exiting.\n", (yyvsp[-7].tnode_ptr) -> NAME);
		}
		else if (no_return_statements != 1) {
			printf("In function %s: only one return statement is allowed (found %d), exiting.\n", (yyvsp[-7].tnode_ptr) -> NAME, no_return_statements);
			exit(0);
		}

		if ((yyvsp[-8].int_val) != function_return_statement_type) {
			printf("Function %s returns value of incorrect type, exiting.\n", (yyvsp[-7].tnode_ptr) -> NAME);
			exit(0);
		}

		// actually generate the function code
		// name is needed to look up the local symbol table
		// $8 will have the slist for functions
		printf("Creating tree for function definition of %s...\n", (yyvsp[-7].tnode_ptr) -> NAME);
		(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_VOID, NODETYPE_FUNCTION_DEFINITION, -1, (yyvsp[-7].tnode_ptr) -> NAME, NULL, (yyvsp[-1].tnode_ptr), NULL, NULL, current_local_symbol_table);

		no_defined_functions++;
		no_return_statements = 0;

		// DO NOT FORGET TO SET current_local_symbol_table AS NULL -- BUG OTHERWISE!!
		current_local_symbol_table = NULL;
		local_symbol_table_counter = 1;

		// this is where the file has to be dealt with because the rule for start won't
		// get reduced unless this has
		if (fp == NULL) {
			// means there are no function definitions
			// also we don't want fp to be initialized multiple times
			fp = fopen("intermediate_code", "w+");
			if (fp == NULL) {
				printf("Error opening file, exiting");
				exit(0);
			}
		}

	}
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 220 "expl.y" /* yacc.c:1646  */
    {

		}
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 224 "expl.y" /* yacc.c:1646  */
    {

		}
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 228 "expl.y" /* yacc.c:1646  */
    {}
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 233 "expl.y" /* yacc.c:1646  */
    {
		// check if an argument of the same name has already been declared
		temp = check_if_already_defined(current_arg_list, (yyvsp[0].tnode_ptr) -> NAME);
		if (temp == 1) {
			printf("Arguments of the function declaration have the same name %s, exiting.\n", (yyvsp[0].tnode_ptr) -> NAME);
			exit(0);
		}
		// append ID to the beginning of the argument list
		current_arg_list = ArgInstall(current_arg_list, variable_type, (yyvsp[0].tnode_ptr) -> NAME, PASS_BY_VALUE);
	}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 244 "expl.y" /* yacc.c:1646  */
    {
			temp = check_if_already_defined(current_arg_list, (yyvsp[0].tnode_ptr) -> NAME);
			if (temp == 1) {
				printf("Arguments of the function declaration have the same name %s, exiting.\n", (yyvsp[0].tnode_ptr) -> NAME);
				exit(0);
			}
			// append ID to the beginning of the argument list
			current_arg_list = ArgInstall(current_arg_list, variable_type, (yyvsp[0].tnode_ptr) -> NAME, PASS_BY_REFERENCE);
		}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 254 "expl.y" /* yacc.c:1646  */
    {
		temp = check_if_already_defined(current_arg_list, (yyvsp[0].tnode_ptr) -> NAME);
		if (temp == 1) {
			printf("Arguments of the function declaration have the same name %s, exiting.\n", (yyvsp[0].tnode_ptr) -> NAME);
			exit(0);
		}
		current_arg_list = ArgInstall(current_arg_list, variable_type, (yyvsp[0].tnode_ptr) -> NAME, PASS_BY_VALUE);
	}
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 263 "expl.y" /* yacc.c:1646  */
    {
		temp = check_if_already_defined(current_arg_list, (yyvsp[0].tnode_ptr) -> NAME);
		if (temp == 1) {
			printf("Arguments of the function declaration have the same name %s, exiting.\n", (yyvsp[0].tnode_ptr) -> NAME);
			exit(0);
		}
		current_arg_list = ArgInstall(current_arg_list, variable_type, (yyvsp[0].tnode_ptr) -> NAME, PASS_BY_REFERENCE);
	}
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 274 "expl.y" /* yacc.c:1646  */
    {

		printf("Processing main function...\n");
		// add main() to the global symbol table
		Ginstall("main", variable_type, 0, NULL);
		struct Gsymbol *main_symbol_table_entry = Glookup("main");
		main_symbol_table_entry -> local_sym_table = current_local_symbol_table;

		// this is where the file has to be dealt with because the rule for start won't
		// get reduced unless this has
		if (fp == NULL) {
			// means there are no function definitions
			// this is where we will have to open the file
			fp = fopen("intermediate_code", "w+");
			if (fp == NULL) {
				printf("Error opening file, exiting");
				exit(0);
			}
		}

		struct Tnode *main_defn = TreeCreate(VAR_TYPE_VOID, NODETYPE_FUNCTION_DEFINITION, -1, "main", NULL, (yyvsp[-2].tnode_ptr), NULL, NULL, current_local_symbol_table);
		code_gen(main_defn);

		fprintf(fp, "START\n");
		// save space for global variables
		// it is the programmer's responsibility to suitably allocate stack pointers
		// SP will be sim_binding - 1
		fprintf(fp, "MOV SP, %d // leave space for global variables\n", sim_binding - 1);
		// leave space for local variables
		int temp = allocate_register();
		// reserve space for return value
		fprintf(fp, "PUSH R%d	// space for return value\n", temp);
		deallocate_register();
		fprintf(fp, "CALL main\n");
		// get the return value
		temp = allocate_register();
		fprintf(fp, "POP R%d\n", temp);
		fprintf(fp, "HALT\n");

		// as always
		current_arg_list = NULL;
		current_arg_binding	= 3;
	}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 324 "expl.y" /* yacc.c:1646  */
    {}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 326 "expl.y" /* yacc.c:1646  */
    {}
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 327 "expl.y" /* yacc.c:1646  */
    {}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 330 "expl.y" /* yacc.c:1646  */
    {}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 332 "expl.y" /* yacc.c:1646  */
    {
		// install this in the LOCAL symbol table for a function
		Linstall(current_local_symbol_table, (yyvsp[0].tnode_ptr) -> NAME, variable_type);
		printf("Installed variable %s\n", (yyvsp[0].tnode_ptr) -> NAME);
	}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 338 "expl.y" /* yacc.c:1646  */
    {
		Linstall(current_local_symbol_table, (yyvsp[0].tnode_ptr) -> NAME, variable_type);
		printf("Installed variable %s\n", (yyvsp[0].tnode_ptr) -> NAME);
	}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 344 "expl.y" /* yacc.c:1646  */
    {
		// generate code for the function here
		// printf("Looking into the function body (code should be generated here)...\n");
		(yyval.tnode_ptr) = (yyvsp[-1].tnode_ptr);
	}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 351 "expl.y" /* yacc.c:1646  */
    {(yyval.tnode_ptr) = TreeCreate(-1, NODETYPE_SLIST, -1, NULL, NULL, (yyvsp[-1].tnode_ptr), (yyvsp[0].tnode_ptr), NULL, current_local_symbol_table);}
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 352 "expl.y" /* yacc.c:1646  */
    {(yyval.tnode_ptr) = (yyvsp[0].tnode_ptr);}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 357 "expl.y" /* yacc.c:1646  */
    {}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 359 "expl.y" /* yacc.c:1646  */
    {}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 360 "expl.y" /* yacc.c:1646  */
    {}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 365 "expl.y" /* yacc.c:1646  */
    {variable_type = VAR_TYPE_INT; (yyval.int_val) = VAR_TYPE_INT;}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 366 "expl.y" /* yacc.c:1646  */
    {variable_type = VAR_TYPE_BOOL; (yyval.int_val) = VAR_TYPE_BOOL;}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 369 "expl.y" /* yacc.c:1646  */
    {}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 371 "expl.y" /* yacc.c:1646  */
    {
		//printf("%s installed as %d\n", $3 -> NAME, variable_type);
		Ginstall((yyvsp[0].tnode_ptr) -> NAME, variable_type, 1, NULL);
	}
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 376 "expl.y" /* yacc.c:1646  */
    {
		printf("Installing array %s\n", (yyvsp[-3].tnode_ptr) -> NAME);
		switch (variable_type) {
			case VAR_TYPE_INT:
				// so the variable is of type integer
				// but it's an array
				// so install it as such
				Ginstall((yyvsp[-3].tnode_ptr) -> NAME, VAR_TYPE_INT_ARR, (yyvsp[-1].tnode_ptr) -> VALUE, NULL);
				break;
			case VAR_TYPE_BOOL:
				// ditto
				Ginstall((yyvsp[-3].tnode_ptr) -> NAME, VAR_TYPE_BOOL_ARR, (yyvsp[-1].tnode_ptr) -> VALUE, NULL);
				break;
		}
	}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 392 "expl.y" /* yacc.c:1646  */
    {
		Ginstall((yyvsp[0].tnode_ptr) -> NAME, variable_type, 1, NULL);
		//printf("%s installed as standalone variable\n", $1 -> NAME);
	}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 397 "expl.y" /* yacc.c:1646  */
    {
		switch (variable_type) {
			case VAR_TYPE_INT:
				// so the variable is of type integer
				// but it's an array
				// so install it as such
				//variable_type = VAR_TYPE_INT_ARR;
				Ginstall((yyvsp[-3].tnode_ptr) -> NAME, VAR_TYPE_INT_ARR, (yyvsp[-1].tnode_ptr) -> VALUE, NULL);
				break;
			case VAR_TYPE_BOOL:
				// ditto
				//variable_type = VAR_TYPE_BOOL_ARR;
				Ginstall((yyvsp[-3].tnode_ptr) -> NAME, VAR_TYPE_BOOL_ARR, (yyvsp[-1].tnode_ptr) -> VALUE, NULL);
				break;
		}
		//printf("%s installed as array\n", $1 -> NAME);
	}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 415 "expl.y" /* yacc.c:1646  */
    {

			// function declaration

			Ginstall((yyvsp[-3].tnode_ptr) -> NAME, variable_type, 0, current_arg_list);	// size is irrelevant here
			no_declared_functions++;
			// so is the SIM_BINDING field
			// but sim_binding value that's used must not be changed, hence the zero for the size
			current_arg_list = NULL;
			current_arg_binding	= 3;

		}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 428 "expl.y" /* yacc.c:1646  */
    {

		Ginstall((yyvsp[-3].tnode_ptr) -> NAME, variable_type, 0, current_arg_list);
		no_declared_functions++;
		current_arg_list = NULL;
		current_arg_binding	= 3;

	}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 438 "expl.y" /* yacc.c:1646  */
    {
			//printf("Making ID node for %s\n", $1 -> NAME);
			(yyvsp[-3].tnode_ptr) -> ArgList = current_arg_list;
			(yyvsp[-3].tnode_ptr) -> Lentry = current_local_symbol_table;
			(yyvsp[-3].tnode_ptr) -> TYPE = find_id_type((yyvsp[-3].tnode_ptr));
			//printf("id type = %d\n", $1 -> TYPE);
			//printf("expr type = %d\n", $3 -> TYPE);
			if ((yyvsp[-3].tnode_ptr) -> TYPE != (yyvsp[-1].tnode_ptr) -> TYPE) {
				printf("Inconsistent types for assignment; exiting.\n");
				exit(0);
			}
			(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_VOID, ASGN, -1, NULL, current_arg_list, (yyvsp[-3].tnode_ptr), (yyvsp[-1].tnode_ptr), NULL, current_local_symbol_table);
		}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 452 "expl.y" /* yacc.c:1646  */
    {
			(yyvsp[-6].tnode_ptr) -> ArgList = current_arg_list;
			(yyvsp[-6].tnode_ptr) -> Lentry = current_local_symbol_table;
			(yyvsp[-6].tnode_ptr) -> TYPE = find_id_type((yyvsp[-6].tnode_ptr));
			if ((yyvsp[-6].tnode_ptr) -> TYPE != VAR_TYPE_INT_ARR && (yyvsp[-6].tnode_ptr) -> TYPE != VAR_TYPE_BOOL_ARR) {
				printf("Trying to index into a non-array variable %s of type %d; exiting.\n", (yyvsp[-6].tnode_ptr) -> NAME, (yyvsp[-6].tnode_ptr) -> TYPE);
				exit(0);
			}
			// means ID is array alright
			// now we just have to check if expr is compatible with ID
			if (((yyvsp[-6].tnode_ptr) -> TYPE == VAR_TYPE_INT_ARR && (yyvsp[-1].tnode_ptr) -> TYPE == VAR_TYPE_BOOL) || ((yyvsp[-6].tnode_ptr) -> TYPE == VAR_TYPE_BOOL_ARR && (yyvsp[-1].tnode_ptr) -> TYPE == VAR_TYPE_INT)) {
				printf("Inconsistent types for assignment; exiting.\n");
				exit(0);
			}
			struct Tnode *new_id_node = TreeCreate((yyvsp[-6].tnode_ptr) -> TYPE, ID, -1, (yyvsp[-6].tnode_ptr) -> NAME, NULL, (yyvsp[-4].tnode_ptr), NULL, NULL, current_local_symbol_table);
			////printf("Making ID array node\n");
			(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_VOID, ASGN, -1, NULL, current_arg_list, new_id_node, (yyvsp[-1].tnode_ptr), NULL, current_local_symbol_table);
		}
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 471 "expl.y" /* yacc.c:1646  */
    {
			(yyvsp[-2].tnode_ptr) -> ArgList = current_arg_list;
			(yyvsp[-2].tnode_ptr) -> Lentry = current_local_symbol_table;
			(yyvsp[-2].tnode_ptr) -> TYPE = find_id_type((yyvsp[-2].tnode_ptr));
			//printf("id type = %d\n", $3 -> TYPE);
			if ((yyvsp[-2].tnode_ptr) -> TYPE != VAR_TYPE_INT) {
 			 printf("READ variable is of incorrect type; exiting.\n");
 			 exit(0);
 		  }
			(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_VOID, READ, -1, NULL, current_arg_list, (yyvsp[-2].tnode_ptr), NULL, NULL, current_local_symbol_table);
		}
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 483 "expl.y" /* yacc.c:1646  */
    {
			(yyvsp[-5].tnode_ptr) -> ArgList = current_arg_list;
			(yyvsp[-5].tnode_ptr) -> Lentry = current_local_symbol_table;
			(yyvsp[-5].tnode_ptr) -> TYPE = find_id_type((yyvsp[-5].tnode_ptr));
			//printf("id type read = %d\n", $3 -> TYPE);
			// this is READ for arrays
			// reason why you can't have READ(expr) (similar to WRITE below)
			// is because READ can only read into VARIABLES (and not expressions).
			// any statements of the form read(a + b + c) (which is an expr) is
			// wrong, but write(a + b + c) works

			// but before all that check the type of variables
			if ((yyvsp[-5].tnode_ptr) -> TYPE != VAR_TYPE_INT_ARR) {
				printf("Incorrect array type for READ statement; exiting.\n");
				exit(0);
			}
			if ((yyvsp[-3].tnode_ptr) -> TYPE != VAR_TYPE_INT) {
				printf("Incorrect index type for array; exiting.\n");
				exit(0);
			}
			struct Tnode *new_id_node = TreeCreate(-1, ID, -1, (yyvsp[-5].tnode_ptr) -> NAME, NULL, (yyvsp[-3].tnode_ptr), NULL, NULL, current_local_symbol_table);
			(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_VOID, READ, -1, NULL, current_arg_list, new_id_node, NULL, NULL, current_local_symbol_table);
		}
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 507 "expl.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-2].tnode_ptr) -> TYPE != VAR_TYPE_INT) {
 			 printf("WRITE variable is of incorrect type; exiting.\n");
 			 exit(0);
 		  }
			(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_VOID, WRITE, -1, NULL, current_arg_list, (yyvsp[-2].tnode_ptr), NULL, NULL, current_local_symbol_table);
		}
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 515 "expl.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-5].tnode_ptr) -> TYPE != VAR_TYPE_BOOL) {
 			 printf("Incorrect type for if condition statement; exiting.\n");
 			 exit(0);
 		  }
			(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_VOID, IF, -1, NULL, current_arg_list, (yyvsp[-5].tnode_ptr), (yyvsp[-2].tnode_ptr), NULL, current_local_symbol_table);
		}
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 523 "expl.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-5].tnode_ptr) -> TYPE != VAR_TYPE_BOOL) {
 			 printf("Incorrect type for while loop condition; exiting.\n");
 			 exit(0);
 		  }
			(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_VOID, WHILE, -1, NULL, current_arg_list, (yyvsp[-5].tnode_ptr), (yyvsp[-2].tnode_ptr), NULL, current_local_symbol_table);
		}
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 531 "expl.y" /* yacc.c:1646  */
    {
			(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_VOID, NODETYPE_RETURN_STMT, -1, NULL, current_arg_list, (yyvsp[-1].tnode_ptr), NULL, NULL, current_local_symbol_table);
			function_return_statement_type = (yyvsp[-1].tnode_ptr) -> TYPE;
			no_return_statements++;
		}
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 539 "expl.y" /* yacc.c:1646  */
    {
		(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_VOID, NODETYPE_FUNCTION_ARG_LIST, -1, NULL, current_arg_list, (yyvsp[-2].tnode_ptr), (yyvsp[0].tnode_ptr), NULL, NULL);
	}
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 543 "expl.y" /* yacc.c:1646  */
    {
		(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_VOID, NODETYPE_FUNCTION_ARG_LIST, -1, NULL, current_arg_list, NULL, (yyvsp[0].tnode_ptr), NULL, NULL);
	}
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 547 "expl.y" /* yacc.c:1646  */
    {}
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 550 "expl.y" /* yacc.c:1646  */
    {
		(yyval.tnode_ptr) = makeOperatorNode(PLUS, (yyvsp[-2].tnode_ptr), (yyvsp[0].tnode_ptr), current_local_symbol_table, current_arg_list);
	}
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 553 "expl.y" /* yacc.c:1646  */
    {(yyval.tnode_ptr) = makeOperatorNode(MUL, (yyvsp[-2].tnode_ptr), (yyvsp[0].tnode_ptr), current_local_symbol_table, current_arg_list);}
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 555 "expl.y" /* yacc.c:1646  */
    {(yyval.tnode_ptr) = makeOperatorNode(MINUS, (yyvsp[-2].tnode_ptr), (yyvsp[0].tnode_ptr), current_local_symbol_table, current_arg_list);}
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 557 "expl.y" /* yacc.c:1646  */
    {(yyval.tnode_ptr) = makeOperatorNode(DIV, (yyvsp[-2].tnode_ptr), (yyvsp[0].tnode_ptr), current_local_symbol_table, current_arg_list);}
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 559 "expl.y" /* yacc.c:1646  */
    {(yyval.tnode_ptr) = TreeCreate((yyvsp[-1].tnode_ptr) -> TYPE, PARENS, -1, NULL, NULL, (yyvsp[-1].tnode_ptr), NULL, NULL, current_local_symbol_table);}
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 561 "expl.y" /* yacc.c:1646  */
    {(yyval.tnode_ptr) = (yyvsp[0].tnode_ptr);}
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 563 "expl.y" /* yacc.c:1646  */
    {
		(yyvsp[0].tnode_ptr) -> Lentry = current_local_symbol_table;
 		(yyvsp[0].tnode_ptr) -> ArgList = current_arg_list;
		// since it can be assumed that this variable would already exist,
		// we can look it up and assign its type to it
		(yyvsp[0].tnode_ptr) -> TYPE = find_id_type((yyvsp[0].tnode_ptr));
    (yyval.tnode_ptr) = (yyvsp[0].tnode_ptr);
   }
#line 2067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 572 "expl.y" /* yacc.c:1646  */
    {
		 // can be referencing an array
		 //printf("ID given array\n");
		 //printf("name = %s\n", $1 -> NAME);
		 (yyvsp[-3].tnode_ptr) -> ArgList = current_arg_list;
		 (yyvsp[-3].tnode_ptr) -> Lentry = current_local_symbol_table;
		 (yyvsp[-3].tnode_ptr) -> TYPE = find_id_type((yyvsp[-3].tnode_ptr));
		 if ((yyvsp[-1].tnode_ptr) -> TYPE != VAR_TYPE_INT) {
			 printf("Line %d: incorrect type for array index; exiting.\n", line_no + 1);
			 exit(0);
		 }
		 switch((yyvsp[-3].tnode_ptr) -> TYPE) {
			 case VAR_TYPE_INT_ARR:
			 	(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_INT, ID, -1, (yyvsp[-3].tnode_ptr) -> NAME, current_arg_list, (yyvsp[-1].tnode_ptr), NULL, NULL, current_local_symbol_table);
				break;
			 case VAR_TYPE_BOOL_ARR:
			 	(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_BOOL, ID, -1, (yyvsp[-3].tnode_ptr) -> NAME, current_arg_list, (yyvsp[-1].tnode_ptr), NULL, NULL, current_local_symbol_table);
				break;
			 default:
			  printf("Trying to index into a non-array variable %s; exiting.\n", (yyvsp[-3].tnode_ptr) -> NAME);
			  exit(0);
		 }
	 }
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 596 "expl.y" /* yacc.c:1646  */
    {
		 // the most complex of them all, function call
		 // just create a new node that will be processed by codegenfunc.c
		 struct Gsymbol *function_call_lookup = Glookup((yyvsp[-3].tnode_ptr) -> NAME);
		 if (function_call_lookup == NULL) {
			 printf("Error, undeclared function %s\n", (yyvsp[-3].tnode_ptr) -> NAME);
			 exit(0);
		 }

		 // check the number of arguments

		 current_fn_args = (yyvsp[-1].tnode_ptr);
		 temp_current_arg_list = function_call_lookup -> ARGLIST;
		 while (current_fn_args != NULL) {
			 if (current_fn_args -> Ptr2 != NULL) {
				 if (current_fn_args -> Ptr2 -> TYPE != temp_current_arg_list -> TYPE) {
					 printf("Incorrect argument type for function call %s at line %d, exiting.\n", (yyvsp[-3].tnode_ptr) -> NAME, line_no);
				 }
				 printf("Line %d: checking %s against argument %s\n", line_no + 1, current_fn_args -> Ptr2 -> NAME, temp_current_arg_list -> NAME);
				 current_fn_args = current_fn_args -> Ptr1;
				 temp_current_arg_list = temp_current_arg_list -> NEXT;
			 }
		 }

		 if (temp_current_arg_list != NULL || current_fn_args != NULL) {
			 printf("temp_current_arg_list has value %s\n", temp_current_arg_list -> NAME);
			 printf("Incorrect number of arguments in function call %s at line %d, exiting.\n", (yyvsp[-3].tnode_ptr) -> NAME, line_no);
			 exit(0);
		 }

		 (yyval.tnode_ptr) = TreeCreate(function_call_lookup -> TYPE, NODETYPE_FUNCTION_CALL, -1, (yyvsp[-3].tnode_ptr) -> NAME, current_arg_list, (yyvsp[-1].tnode_ptr), NULL, NULL, current_local_symbol_table);
		 //current_arg_list = NULL;
	 }
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 630 "expl.y" /* yacc.c:1646  */
    {
		 (yyval.tnode_ptr) = makeOperatorNode(LT, (yyvsp[-2].tnode_ptr), (yyvsp[0].tnode_ptr), current_local_symbol_table, current_arg_list);
	 }
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 634 "expl.y" /* yacc.c:1646  */
    {
		 (yyval.tnode_ptr) = makeOperatorNode(GT, (yyvsp[-2].tnode_ptr), (yyvsp[0].tnode_ptr), current_local_symbol_table, current_arg_list);
	 }
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 638 "expl.y" /* yacc.c:1646  */
    {
		 (yyval.tnode_ptr) = makeOperatorNode(EQ, (yyvsp[-2].tnode_ptr), (yyvsp[0].tnode_ptr), current_local_symbol_table, current_arg_list);
	 }
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 642 "expl.y" /* yacc.c:1646  */
    {
		 (yyval.tnode_ptr) = makeOperatorNode(LE, (yyvsp[-2].tnode_ptr), (yyvsp[0].tnode_ptr), current_local_symbol_table, current_arg_list);
	 }
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 646 "expl.y" /* yacc.c:1646  */
    {
		 (yyval.tnode_ptr) = makeOperatorNode(GE, (yyvsp[-2].tnode_ptr), (yyvsp[0].tnode_ptr), current_local_symbol_table, current_arg_list);
	 }
#line 2173 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2177 "y.tab.c" /* yacc.c:1646  */
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
#line 651 "expl.y" /* yacc.c:1906  */


yyerror(char const *s)
{
    printf("yyerror, %s: '%s' in line %d\n", s, yytext, line_no + 1);
}

int main(int argc, char *argv[]) {
	if(argc > 1)
	{
    	FILE *fp = fopen(argv[1],"r");
    	if(fp)
        	yyin = fp;
	}
	yyparse();

	return 0;
}
