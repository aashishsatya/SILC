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

	int yylex(void);
	extern FILE *yyin;
	extern int yylineno;
	extern char *yytext;

  //int *var[26];
	int variable_type;	// this will store the type of the variable that is being processed

#line 82 "y.tab.c" /* yacc.c:339  */

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
    RETURN = 285
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 17 "expl.y" /* yacc.c:355  */

	int int_val;
	struct  Tnode *tnode_ptr;

#line 187 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 202 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   265

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  150

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    37,     2,
      31,    32,     2,     2,    36,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    90,    91,    94,   160,   164,   168,   173,
     178,   183,   187,   193,   243,   245,   246,   249,   251,   257,
     263,   270,   271,   276,   278,   279,   284,   285,   288,   290,
     295,   310,   315,   333,   345,   354,   368,   387,   399,   423,
     431,   439,   447,   453,   457,   461,   464,   467,   469,   471,
     473,   475,   477,   486,   510,   521,   525,   529
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
  "ENDOFFILE", "BEGINNING", "END", "MAIN", "RETURN", "'('", "')'", "'{'",
  "'}'", "';'", "','", "'&'", "'['", "']'", "$accept", "start",
  "funcDefnList", "funcDefn", "ArgList", "vbl_declns", "MainBlock",
  "localDeclarations", "local_dec_list", "local_dec", "local_id_list",
  "funcBody", "slist", "declarations", "dec_list", "type", "dec",
  "id_list", "stmt", "ArgListFunctionCall", "expr", YY_NULLPTR
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
     285,    40,    41,   123,   125,    59,    44,    38,    91,    93
};
# endif

#define YYPACT_NINF -73

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-73)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -17,    26,    10,   -73,   -73,   -73,     8,    37,    26,   -73,
      26,   -73,    58,    34,   -73,   -73,    30,    20,    26,    39,
     -73,    46,   -73,    35,    44,    47,   -12,    49,    61,    26,
      70,   -73,   -73,    75,    55,   -73,    26,    92,   101,    91,
     -73,    26,   -11,   102,    98,   105,   130,   -73,   -73,   123,
     -73,   -73,   130,    26,   126,   -73,   128,   133,    26,   142,
     228,   228,   132,   -73,   -73,   -73,    79,   136,   137,   139,
     140,    -1,    -3,   179,   -73,   192,   -73,   -73,   151,   154,
      -3,    -3,    -3,    -3,    -3,    81,   -73,    -3,   100,   145,
     -73,   -73,   -73,   -24,     9,   141,   155,   119,    74,    -3,
      -3,   174,    -3,    -3,    -3,    -3,    -3,    -3,    -3,   -73,
     -73,   146,    -3,   153,   157,   167,   -73,   184,     0,   244,
      77,   -73,    53,    25,   138,   138,   138,    25,    53,   -73,
      97,   -73,   228,   228,    -3,   -73,    -3,   -73,   160,   206,
     219,   122,   244,   158,   161,   165,   -73,   -73,   -73,   -73
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     4,    27,    26,     0,     0,    25,     1,
       0,    23,    31,     0,    24,     3,     0,     0,     8,     0,
      28,     0,     2,     0,     0,     0,     0,     0,    29,     8,
       0,    34,    11,     0,     7,    32,     8,     0,     0,     0,
      12,     8,     0,     0,     0,     0,     0,     6,     9,     0,
      33,    30,     0,     0,     0,    10,     0,     0,    16,     0,
       0,     0,     0,    14,    15,    19,     0,     0,     0,     0,
       0,     0,     0,     0,    22,     0,     5,    17,     0,     0,
       0,     0,     0,     0,     0,    52,    51,     0,     0,     0,
      21,    20,    18,     0,     0,     0,     0,     0,     0,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    42,
      13,     0,     0,     0,     0,     0,    35,     0,     0,    44,
       0,    50,    46,    47,    55,    56,    57,    49,    48,    37,
       0,    39,     0,     0,     0,    54,     0,    53,     0,     0,
       0,     0,    43,     0,     0,     0,    36,    38,    40,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -73,   -73,   -73,   -73,    24,   -73,   -73,   149,   144,   -73,
     -73,   -73,   -61,   -73,   197,     1,   -73,   -73,   -72,   -73,
     -60
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    10,    15,    25,    34,    16,    54,    57,    58,
      66,    62,    73,     3,     6,    26,     8,    13,    74,   118,
      88
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      75,    90,     7,    90,    83,     1,    32,    48,   111,     7,
       9,    17,   102,   103,   112,    85,    86,   104,   105,   106,
      94,    95,    96,    97,    98,    33,    49,   101,    87,   107,
     108,    11,   135,   104,   105,   106,   136,    84,    23,   119,
     120,   113,   122,   123,   124,   125,   126,   127,   128,    24,
       4,     5,   130,    38,    59,    12,    22,   103,    27,    59,
      43,   104,   105,   106,    28,    47,    29,    90,    90,    20,
      21,   139,   140,   107,   141,    30,   142,   102,   103,    31,
     102,   103,   104,   105,   106,   104,   105,   106,    35,    18,
      41,    42,    36,    40,   107,   108,    19,   107,   108,    37,
     102,   103,    39,   102,   103,   104,   105,   106,   104,   105,
     106,    44,    99,   117,    77,    78,   137,   107,   108,   100,
     107,   108,   102,   103,    46,   102,   103,   104,   105,   106,
     104,   105,   106,    45,    50,   109,   138,    51,    52,   107,
     108,    55,   107,   108,   102,   103,    -1,    -1,    -1,   104,
     105,   106,    53,    60,   116,    61,    63,   146,   102,   103,
      65,   107,   108,   104,   105,   106,    76,    79,    80,    92,
      81,    82,    93,   114,   132,   107,   108,   102,   103,   110,
     133,   129,   104,   105,   106,    67,    68,   115,   131,   134,
      69,    70,   143,   147,   107,   108,   148,    71,    67,    68,
     149,    56,    64,    69,    70,    14,   121,    89,     0,    72,
      71,     0,    67,    68,     0,     0,     0,    69,    70,     0,
      91,   144,    72,     0,    71,    67,    68,     0,     0,     0,
      69,    70,     0,   145,    67,    68,    72,    71,     0,    69,
      70,     0,     0,     0,     0,     0,    71,   102,   103,    72,
       0,     0,   104,   105,   106,     0,     0,     0,    72,     0,
       0,     0,     0,     0,   107,   108
};

static const yytype_int16 yycheck[] =
{
      61,    73,     1,    75,     5,    22,    18,    18,    32,     8,
       0,    10,     3,     4,    38,    18,    19,     8,     9,    10,
      80,    81,    82,    83,    84,    37,    37,    87,    31,    20,
      21,    23,    32,     8,     9,    10,    36,    38,    18,    99,
     100,    32,   102,   103,   104,   105,   106,   107,   108,    29,
      24,    25,   112,    29,    53,    18,    26,     4,    19,    58,
      36,     8,     9,    10,    18,    41,    31,   139,   140,    35,
      36,   132,   133,    20,   134,    31,   136,     3,     4,    32,
       3,     4,     8,     9,    10,     8,     9,    10,    39,    31,
      35,    36,    31,    18,    20,    21,    38,    20,    21,    38,
       3,     4,    32,     3,     4,     8,     9,    10,     8,     9,
      10,    19,    31,    39,    35,    36,    39,    20,    21,    38,
      20,    21,     3,     4,    33,     3,     4,     8,     9,    10,
       8,     9,    10,    32,    32,    35,    39,    39,    33,    20,
      21,    18,    20,    21,     3,     4,     8,     9,    10,     8,
       9,    10,    22,    27,    35,    27,    23,    35,     3,     4,
      18,    20,    21,     8,     9,    10,    34,    31,    31,    18,
      31,    31,    18,    32,    17,    20,    21,     3,     4,    34,
      13,    35,     8,     9,    10,     6,     7,    32,    35,     5,
      11,    12,    32,    35,    20,    21,    35,    18,     6,     7,
      35,    52,    58,    11,    12,     8,    32,    28,    -1,    30,
      18,    -1,     6,     7,    -1,    -1,    -1,    11,    12,    -1,
      28,    15,    30,    -1,    18,     6,     7,    -1,    -1,    -1,
      11,    12,    -1,    14,     6,     7,    30,    18,    -1,    11,
      12,    -1,    -1,    -1,    -1,    -1,    18,     3,     4,    30,
      -1,    -1,     8,     9,    10,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    20,    21
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    22,    41,    53,    24,    25,    54,    55,    56,     0,
      42,    23,    18,    57,    54,    43,    46,    55,    31,    38,
      35,    36,    26,    18,    29,    44,    55,    19,    18,    31,
      31,    32,    18,    37,    45,    39,    31,    38,    44,    32,
      18,    35,    36,    44,    19,    32,    33,    44,    18,    37,
      32,    39,    33,    22,    47,    18,    47,    48,    49,    55,
      27,    27,    51,    23,    48,    18,    50,     6,     7,    11,
      12,    18,    30,    52,    58,    52,    34,    35,    36,    31,
      31,    31,    31,     5,    38,    18,    19,    31,    60,    28,
      58,    28,    18,    18,    60,    60,    60,    60,    60,    31,
      38,    60,     3,     4,     8,     9,    10,    20,    21,    35,
      34,    32,    38,    32,    32,    32,    35,    39,    59,    60,
      60,    32,    60,    60,    60,    60,    60,    60,    60,    35,
      60,    35,    17,    13,     5,    32,    36,    39,    39,    52,
      52,    60,    60,    32,    15,    14,    35,    35,    35,    35
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    44,    44,    44,    45,
      45,    45,    45,    46,    47,    48,    48,    49,    50,    50,
      51,    52,    52,    53,    54,    54,    55,    55,    56,    57,
      57,    57,    57,    57,    57,    58,    58,    58,    58,    58,
      58,    58,    58,    59,    59,    59,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     2,     0,     9,     4,     2,     0,     3,
       4,     1,     2,    10,     3,     2,     1,     3,     3,     1,
       3,     2,     1,     3,     2,     1,     1,     1,     3,     3,
       6,     1,     4,     6,     4,     4,     7,     5,     8,     5,
       8,     8,     3,     3,     1,     0,     3,     3,     3,     3,
       3,     1,     1,     4,     4,     3,     3,     3
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
#line 67 "expl.y" /* yacc.c:1646  */
    {

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
#line 1413 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 90 "expl.y" /* yacc.c:1646  */
    {code_gen((yyvsp[0].tnode_ptr));}
#line 1419 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 91 "expl.y" /* yacc.c:1646  */
    {}
#line 1425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 94 "expl.y" /* yacc.c:1646  */
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

		// actually generate the function code
		// name is needed to look up the local symbol table
		// $8 will have the slist for functions
		printf("Creating tree for function definition of %s...\n", (yyvsp[-7].tnode_ptr) -> NAME);
		(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_VOID, NODETYPE_FUNCTION_DEFINITION, -1, (yyvsp[-7].tnode_ptr) -> NAME, NULL, (yyvsp[-1].tnode_ptr), NULL, NULL, current_local_symbol_table);

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
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 160 "expl.y" /* yacc.c:1646  */
    {

		}
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 164 "expl.y" /* yacc.c:1646  */
    {

		}
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 168 "expl.y" /* yacc.c:1646  */
    {}
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 173 "expl.y" /* yacc.c:1646  */
    {
		// append ID to the beginning of the argument list
		current_arg_list = ArgInstall(current_arg_list, variable_type, (yyvsp[0].tnode_ptr) -> NAME, PASS_BY_VALUE);
	}
#line 1525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 178 "expl.y" /* yacc.c:1646  */
    {
			// append ID to the beginning of the argument list
			current_arg_list = ArgInstall(current_arg_list, variable_type, (yyvsp[0].tnode_ptr) -> NAME, PASS_BY_REFERENCE);
		}
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 183 "expl.y" /* yacc.c:1646  */
    {
		current_arg_list = ArgInstall(current_arg_list, variable_type, (yyvsp[0].tnode_ptr) -> NAME, PASS_BY_VALUE);
	}
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 187 "expl.y" /* yacc.c:1646  */
    {
		current_arg_list = ArgInstall(current_arg_list, variable_type, (yyvsp[0].tnode_ptr) -> NAME, PASS_BY_REFERENCE);
	}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 193 "expl.y" /* yacc.c:1646  */
    {

		printf("Processing main function...\n");
		// add main() to the global symbol table
		Ginstall("main", variable_type, 0, current_arg_list);
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
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 243 "expl.y" /* yacc.c:1646  */
    {}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 245 "expl.y" /* yacc.c:1646  */
    {}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 246 "expl.y" /* yacc.c:1646  */
    {}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 249 "expl.y" /* yacc.c:1646  */
    {}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 251 "expl.y" /* yacc.c:1646  */
    {
		// install this in the LOCAL symbol table for a function
		Linstall(current_local_symbol_table, (yyvsp[0].tnode_ptr) -> NAME, variable_type);
		printf("Installed variable %s\n", (yyvsp[0].tnode_ptr) -> NAME);
	}
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 257 "expl.y" /* yacc.c:1646  */
    {
		Linstall(current_local_symbol_table, (yyvsp[0].tnode_ptr) -> NAME, variable_type);
		printf("Installed variable %s\n", (yyvsp[0].tnode_ptr) -> NAME);
	}
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 263 "expl.y" /* yacc.c:1646  */
    {
		// generate code for the function here
		// printf("Looking into the function body (code should be generated here)...\n");
		(yyval.tnode_ptr) = (yyvsp[-1].tnode_ptr);
	}
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 270 "expl.y" /* yacc.c:1646  */
    {(yyval.tnode_ptr) = TreeCreate(-1, NODETYPE_SLIST, -1, NULL, NULL, (yyvsp[-1].tnode_ptr), (yyvsp[0].tnode_ptr), NULL, current_local_symbol_table);}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 271 "expl.y" /* yacc.c:1646  */
    {(yyval.tnode_ptr) = (yyvsp[0].tnode_ptr);}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 276 "expl.y" /* yacc.c:1646  */
    {}
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 278 "expl.y" /* yacc.c:1646  */
    {}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 279 "expl.y" /* yacc.c:1646  */
    {}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 284 "expl.y" /* yacc.c:1646  */
    {variable_type = VAR_TYPE_INT;}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 285 "expl.y" /* yacc.c:1646  */
    {variable_type = VAR_TYPE_BOOL;}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 288 "expl.y" /* yacc.c:1646  */
    {}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 290 "expl.y" /* yacc.c:1646  */
    {
		//printf("%s installed as %d\n", $3 -> NAME, variable_type);
		Ginstall((yyvsp[0].tnode_ptr) -> NAME, variable_type, 1, NULL);
	}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 295 "expl.y" /* yacc.c:1646  */
    {
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
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 310 "expl.y" /* yacc.c:1646  */
    {
		Ginstall((yyvsp[0].tnode_ptr) -> NAME, variable_type, 1, NULL);
		//printf("%s installed as standalone variable\n", $1 -> NAME);
	}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 315 "expl.y" /* yacc.c:1646  */
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
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 333 "expl.y" /* yacc.c:1646  */
    {

			// function declaration

			Ginstall((yyvsp[-3].tnode_ptr) -> NAME, variable_type, 0, current_arg_list);	// size is irrelevant here
			// so is the SIM_BINDING field
			// but sim_binding value that's used must not be changed, hence the zero for the size
			current_arg_list = NULL;
			current_arg_binding	= 3;

		}
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 345 "expl.y" /* yacc.c:1646  */
    {

		Ginstall((yyvsp[-3].tnode_ptr) -> NAME, variable_type, 0, current_arg_list);
		current_arg_list = NULL;
		current_arg_binding	= 3;

	}
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 354 "expl.y" /* yacc.c:1646  */
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
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 368 "expl.y" /* yacc.c:1646  */
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
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 387 "expl.y" /* yacc.c:1646  */
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
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 399 "expl.y" /* yacc.c:1646  */
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
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 423 "expl.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-2].tnode_ptr) -> TYPE != VAR_TYPE_INT) {
 			 printf("WRITE variable is of incorrect type; exiting.\n");
 			 exit(0);
 		  }
			(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_VOID, WRITE, -1, NULL, current_arg_list, (yyvsp[-2].tnode_ptr), NULL, NULL, current_local_symbol_table);
		}
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 431 "expl.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-5].tnode_ptr) -> TYPE != VAR_TYPE_BOOL) {
 			 printf("Incorrect type for if condition statement; exiting.\n");
 			 exit(0);
 		  }
			(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_VOID, IF, -1, NULL, current_arg_list, (yyvsp[-5].tnode_ptr), (yyvsp[-2].tnode_ptr), NULL, current_local_symbol_table);
		}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 439 "expl.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-5].tnode_ptr) -> TYPE != VAR_TYPE_BOOL) {
 			 printf("Incorrect type for while loop condition; exiting.\n");
 			 exit(0);
 		  }
			(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_VOID, WHILE, -1, NULL, current_arg_list, (yyvsp[-5].tnode_ptr), (yyvsp[-2].tnode_ptr), NULL, current_local_symbol_table);
		}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 447 "expl.y" /* yacc.c:1646  */
    {
			(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_VOID, NODETYPE_RETURN_STMT, -1, NULL, current_arg_list, (yyvsp[-1].tnode_ptr), NULL, NULL, current_local_symbol_table);
		}
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 453 "expl.y" /* yacc.c:1646  */
    {
		(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_VOID, NODETYPE_FUNCTION_ARG_LIST, -1, NULL, current_arg_list, (yyvsp[-2].tnode_ptr), (yyvsp[0].tnode_ptr), NULL, NULL);
	}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 457 "expl.y" /* yacc.c:1646  */
    {
		(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_VOID, NODETYPE_FUNCTION_ARG_LIST, -1, NULL, current_arg_list, NULL, (yyvsp[0].tnode_ptr), NULL, NULL);
	}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 461 "expl.y" /* yacc.c:1646  */
    {}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 464 "expl.y" /* yacc.c:1646  */
    {
		(yyval.tnode_ptr) = makeOperatorNode(PLUS, (yyvsp[-2].tnode_ptr), (yyvsp[0].tnode_ptr), current_local_symbol_table, current_arg_list);
	}
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 467 "expl.y" /* yacc.c:1646  */
    {(yyval.tnode_ptr) = makeOperatorNode(MUL, (yyvsp[-2].tnode_ptr), (yyvsp[0].tnode_ptr), current_local_symbol_table, current_arg_list);}
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 469 "expl.y" /* yacc.c:1646  */
    {(yyval.tnode_ptr) = makeOperatorNode(MINUS, (yyvsp[-2].tnode_ptr), (yyvsp[0].tnode_ptr), current_local_symbol_table, current_arg_list);}
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 471 "expl.y" /* yacc.c:1646  */
    {(yyval.tnode_ptr) = makeOperatorNode(DIV, (yyvsp[-2].tnode_ptr), (yyvsp[0].tnode_ptr), current_local_symbol_table, current_arg_list);}
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 473 "expl.y" /* yacc.c:1646  */
    {(yyval.tnode_ptr) = TreeCreate((yyvsp[-1].tnode_ptr) -> TYPE, PARENS, -1, NULL, NULL, (yyvsp[-1].tnode_ptr), NULL, NULL, current_local_symbol_table);}
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 475 "expl.y" /* yacc.c:1646  */
    {(yyval.tnode_ptr) = (yyvsp[0].tnode_ptr);}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 477 "expl.y" /* yacc.c:1646  */
    {
		(yyvsp[0].tnode_ptr) -> Lentry = current_local_symbol_table;
 		(yyvsp[0].tnode_ptr) -> ArgList = current_arg_list;
		// since it can be assumed that this variable would already exist,
		// we can look it up and assign its type to it
		(yyvsp[0].tnode_ptr) -> TYPE = find_id_type((yyvsp[0].tnode_ptr));
    (yyval.tnode_ptr) = (yyvsp[0].tnode_ptr);
   }
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 486 "expl.y" /* yacc.c:1646  */
    {
		 // can be referencing an array
		 //printf("ID given array\n");
		 //printf("name = %s\n", $1 -> NAME);
		 (yyvsp[-3].tnode_ptr) -> ArgList = current_arg_list;
		 (yyvsp[-3].tnode_ptr) -> Lentry = current_local_symbol_table;
		 (yyvsp[-3].tnode_ptr) -> TYPE = find_id_type((yyvsp[-3].tnode_ptr));
		 if ((yyvsp[-1].tnode_ptr) -> TYPE != VAR_TYPE_INT) {
			 printf("Incorrect type for array index; exiting.\n");
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
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 510 "expl.y" /* yacc.c:1646  */
    {
		 // the most complex of them all, function call
		 // just create a new node that will be processed by codegenfunc.c
		 struct Gsymbol *function_call_lookup = Glookup((yyvsp[-3].tnode_ptr) -> NAME);
		 if (function_call_lookup == NULL) {
			 printf("Error, undeclared function %s\n", (yyvsp[-3].tnode_ptr) -> NAME);
			 exit(0);
		 }
		 (yyval.tnode_ptr) = TreeCreate(function_call_lookup -> TYPE, NODETYPE_FUNCTION_CALL, -1, (yyvsp[-3].tnode_ptr) -> NAME, current_arg_list, (yyvsp[-1].tnode_ptr), NULL, NULL, current_local_symbol_table);
	 }
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 521 "expl.y" /* yacc.c:1646  */
    {
		 (yyval.tnode_ptr) = makeOperatorNode(LT, (yyvsp[-2].tnode_ptr), (yyvsp[0].tnode_ptr), current_local_symbol_table, current_arg_list);
	 }
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 525 "expl.y" /* yacc.c:1646  */
    {
		 (yyval.tnode_ptr) = makeOperatorNode(GT, (yyvsp[-2].tnode_ptr), (yyvsp[0].tnode_ptr), current_local_symbol_table, current_arg_list);
	 }
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 529 "expl.y" /* yacc.c:1646  */
    {
		 (yyval.tnode_ptr) = makeOperatorNode(EQ, (yyvsp[-2].tnode_ptr), (yyvsp[0].tnode_ptr), current_local_symbol_table, current_arg_list);
	 }
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2059 "y.tab.c" /* yacc.c:1646  */
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
#line 534 "expl.y" /* yacc.c:1906  */


yyerror(char const *s)
{
    printf("yyerror, %s: '%s' in line %d\n", s, yytext, yylineno);
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
