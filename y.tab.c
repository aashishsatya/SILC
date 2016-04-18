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
	extern int line_no;

  //int *var[26];
	struct Typetable *variable_type;	// this will store the type of the variable that is being processed

#line 83 "y.tab.c" /* yacc.c:339  */

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
    ENDOFFILE = 279,
    BEGINNING = 280,
    END = 281,
    MAIN = 282,
    RETURN = 283,
    LE = 284,
    GE = 285,
    TYPEDEF = 286
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
#define ENDOFFILE 279
#define BEGINNING 280
#define END 281
#define MAIN 282
#define RETURN 283
#define LE 284
#define GE 285
#define TYPEDEF 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 18 "expl.y" /* yacc.c:355  */

	int int_val;
	struct  Tnode *tnode_ptr;
	struct Fieldlist *fields_ptr;
	struct Typetable *type_entry;

#line 192 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 207 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   287

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  170

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    38,     2,
      36,    37,     2,     2,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    34,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,     2,    33,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    72,    72,   100,   110,   116,   119,   149,   157,   163,
     168,   211,   215,   222,   223,   226,   308,   312,   316,   321,
     332,   342,   351,   362,   412,   414,   415,   418,   420,   426,
     432,   439,   440,   445,   447,   448,   453,   459,   461,   466,
     472,   477,   482,   495,   505,   519,   539,   551,   576,   584,
     592,   600,   608,   612,   616,   619,   622,   624,   626,   628,
     630,   632,   641,   660,   694,   698,   702,   706,   710
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PLUS", "MUL", "ASGN", "READ", "WRITE",
  "LT", "GT", "EQ", "IF", "WHILE", "DO", "ENDWHILE", "ENDIF", "PARENS",
  "THEN", "ID", "NUM", "DIV", "MINUS", "DECL", "ENDDECL", "ENDOFFILE",
  "BEGINNING", "END", "MAIN", "RETURN", "LE", "GE", "TYPEDEF", "'{'",
  "'}'", "';'", "','", "'('", "')'", "'&'", "'['", "']'", "$accept",
  "start", "starterCode", "userDataTypeDecln", "dataTypeDecln",
  "dataTypeName", "fieldDeclarations", "field_decln", "user_type_list",
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
     285,   286,   123,   125,    59,    44,    40,    41,    38,    91,
      93
};
# endif

#define YYPACT_NINF -92

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-92)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -92,    21,   -92,   -92,   -12,    33,    70,   -92,   -92,   -92,
       3,    76,    33,   -92,    71,    33,   -92,   -16,    47,   -92,
      82,   -92,    41,    35,    33,    83,   -92,    96,   102,    68,
     -92,   -92,    91,    95,   100,     4,    99,    16,   -92,   107,
     -92,   -92,    33,   108,   -92,   -92,   133,   141,   -92,    33,
     135,   -92,   147,   122,   130,   -92,    33,    36,   131,   145,
     -92,   148,   167,   -92,   -92,   173,   -92,   -92,   167,    33,
     175,   -92,   176,   179,    33,   185,   146,   146,   180,   -92,
     -92,   -92,   144,   181,   182,   187,   193,    -3,    72,   221,
     -92,   244,   -92,   -92,   196,   220,    72,    72,    72,    72,
      72,    20,   -92,    72,   163,   207,   -92,   -92,   -92,   -24,
      89,   103,   126,   178,    37,    72,    72,   140,    72,    72,
      72,    72,    72,    72,    72,    72,    72,   -92,   -92,   208,
      72,   209,   227,   241,   -92,   254,    52,   216,    40,   -92,
     186,     8,   257,   257,   257,     8,   186,   257,   257,   -92,
      75,   -92,   146,   146,    72,    72,   -92,   -92,   224,   110,
     246,   201,   216,   229,   234,   235,   -92,   -92,   -92,   -92
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     5,     1,     0,     0,     0,     4,    14,    36,
       0,     0,    35,     7,     0,     0,    33,    40,     0,    34,
       0,    13,     0,     0,    18,     0,    37,     0,     0,     0,
       9,     2,     0,     0,     0,     0,     0,    38,    12,     0,
       6,     8,    18,     0,    43,    21,     0,    17,    41,    18,
       0,    10,     0,     0,     0,    22,    18,     0,     0,     0,
      11,     0,     0,    16,    19,     0,    42,    39,     0,     0,
       0,    20,     0,     0,    26,     0,     0,     0,     0,    24,
      25,    29,     0,     0,     0,     0,     0,     0,     0,     0,
      32,     0,    15,    27,     0,     0,     0,     0,     0,     0,
       0,    61,    60,     0,     0,     0,    31,    30,    28,     0,
       0,     0,     0,     0,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,    23,     0,
       0,     0,     0,     0,    44,     0,     0,    53,     0,    59,
      55,    56,    64,    65,    66,    58,    57,    67,    68,    46,
       0,    48,     0,     0,     0,     0,    63,    62,     0,     0,
       0,     0,    52,     0,     0,     0,    45,    47,    49,    50
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   242,   -92,   -92,
     -92,   192,   -92,   -92,   205,   202,   -92,   -92,   -92,   -77,
     -92,   263,    -1,   -92,   -92,   -88,   -92,   -91
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     4,     7,    14,    29,    30,    39,    15,
      21,    34,    47,    22,    70,    73,    74,    82,    78,    89,
       8,    10,    35,    12,    18,    90,   136,   104
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      91,   106,    99,   106,    11,   110,   111,   112,   113,   114,
       5,    11,   117,   129,    23,   130,   120,   121,   122,     6,
      24,     3,    45,    25,   137,   138,    16,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   100,   125,   126,   150,
     118,   119,    46,   118,   119,   120,   121,   122,   120,   121,
     122,     9,    49,    32,    64,    50,   115,   123,   124,   116,
     123,   124,    33,   161,   162,    31,   125,   126,    75,   125,
     126,   106,   106,    75,    65,   159,   160,   135,   118,   119,
     157,    26,    27,   120,   121,   122,    28,   155,    13,   156,
     101,   102,   118,   119,    17,   123,   124,   120,   121,   122,
      28,    40,    36,    20,   125,   126,   118,   119,   103,   123,
     124,   120,   121,   122,    37,   158,    83,    84,   125,   126,
      38,    85,    86,   123,   124,   164,   131,    42,    87,   118,
     119,    43,   125,   126,   120,   121,   122,    44,    88,    48,
     132,    51,    52,   118,   119,    54,   123,   124,   120,   121,
     122,    55,    83,    84,    59,   125,   126,    85,    86,    61,
     123,   124,    62,   133,    87,    60,   118,   119,    66,   125,
     126,   120,   121,   122,    88,    56,    57,   139,    93,    94,
      68,   118,   119,   123,   124,    67,   120,   121,   122,    69,
     119,    71,   125,   126,   120,   121,   122,   127,   123,   124,
      76,    77,    79,    81,   118,   119,   123,   125,   126,   120,
     121,   122,   134,    92,   108,   125,   126,    95,    96,   118,
     119,   123,   124,    97,   120,   121,   122,    83,    84,    98,
     125,   126,    85,    86,    53,   166,   123,   124,   109,    87,
     128,    58,   149,   151,   152,   125,   126,   105,    63,    88,
      83,    84,    83,    84,   153,    85,    86,    85,    86,   154,
     165,   163,    87,   167,    87,    -1,    -1,    -1,   168,   169,
     107,    41,    88,    72,    88,    19,    80,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    -1,    -1
};

static const yytype_int16 yycheck[] =
{
      77,    89,     5,    91,     5,    96,    97,    98,    99,   100,
      22,    12,   103,    37,    15,    39,     8,     9,    10,    31,
      36,     0,    18,    39,   115,   116,    23,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    39,    29,    30,   130,
       3,     4,    38,     3,     4,     8,     9,    10,     8,     9,
      10,    18,    36,    18,    18,    39,    36,    20,    21,    39,
      20,    21,    27,   154,   155,    24,    29,    30,    69,    29,
      30,   159,   160,    74,    38,   152,   153,    40,     3,     4,
      40,    34,    35,     8,     9,    10,    18,    35,    18,    37,
      18,    19,     3,     4,    18,    20,    21,     8,     9,    10,
      18,    33,    19,    32,    29,    30,     3,     4,    36,    20,
      21,     8,     9,    10,    18,    40,     6,     7,    29,    30,
      18,    11,    12,    20,    21,    15,    37,    36,    18,     3,
       4,    36,    29,    30,     8,     9,    10,    37,    28,    40,
      37,    34,    35,     3,     4,    37,    20,    21,     8,     9,
      10,    18,     6,     7,    19,    29,    30,    11,    12,    37,
      20,    21,    32,    37,    18,    18,     3,     4,    37,    29,
      30,     8,     9,    10,    28,    34,    35,    37,    34,    35,
      32,     3,     4,    20,    21,    40,     8,     9,    10,    22,
       4,    18,    29,    30,     8,     9,    10,    34,    20,    21,
      25,    25,    23,    18,     3,     4,    20,    29,    30,     8,
       9,    10,    34,    33,    18,    29,    30,    36,    36,     3,
       4,    20,    21,    36,     8,     9,    10,     6,     7,    36,
      29,    30,    11,    12,    42,    34,    20,    21,    18,    18,
      33,    49,    34,    34,    17,    29,    30,    26,    56,    28,
       6,     7,     6,     7,    13,    11,    12,    11,    12,     5,
      14,    37,    18,    34,    18,     8,     9,    10,    34,    34,
      26,    29,    28,    68,    28,    12,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,    43,     0,    44,    22,    31,    45,    61,    18,
      62,    63,    64,    18,    46,    50,    23,    18,    65,    62,
      32,    51,    54,    63,    36,    39,    34,    35,    18,    47,
      48,    24,    18,    27,    52,    63,    19,    18,    18,    49,
      33,    48,    36,    36,    37,    18,    38,    53,    40,    36,
      39,    34,    35,    52,    37,    18,    34,    35,    52,    19,
      18,    37,    32,    52,    18,    38,    37,    40,    32,    22,
      55,    18,    55,    56,    57,    63,    25,    25,    59,    23,
      56,    18,    58,     6,     7,    11,    12,    18,    28,    60,
      66,    60,    33,    34,    35,    36,    36,    36,    36,     5,
      39,    18,    19,    36,    68,    26,    66,    26,    18,    18,
      68,    68,    68,    68,    68,    36,    39,    68,     3,     4,
       8,     9,    10,    20,    21,    29,    30,    34,    33,    37,
      39,    37,    37,    37,    34,    40,    67,    68,    68,    37,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    34,
      68,    34,    17,    13,     5,    35,    37,    40,    40,    60,
      60,    68,    68,    37,    15,    14,    34,    34,    34,    34
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    44,    44,    45,    46,    47,    47,
      48,    49,    49,    50,    50,    51,    52,    52,    52,    53,
      53,    53,    53,    54,    55,    56,    56,    57,    58,    58,
      59,    60,    60,    61,    62,    62,    63,    64,    65,    65,
      65,    65,    65,    65,    66,    66,    66,    66,    66,    66,
      66,    66,    67,    67,    67,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     0,     2,     0,     5,     1,     2,     1,
       3,     3,     1,     2,     0,     9,     4,     2,     0,     3,
       4,     1,     2,    10,     3,     2,     1,     3,     3,     1,
       3,     2,     1,     3,     2,     1,     1,     3,     3,     6,
       1,     4,     6,     4,     4,     7,     5,     8,     5,     8,
       8,     3,     3,     1,     0,     3,     3,     3,     3,     3,
       1,     1,     4,     4,     3,     3,     3,     3,     3
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
#line 1439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 100 "expl.y" /* yacc.c:1646  */
    {
	// this code was just meant to initialize TypeTableCreate()
	if (VAR_TYPE_INT == NULL) {
		printf("TypeTableCreate called by starter code.\n");
		TypeTableCreate();
	}
}
#line 1451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 110 "expl.y" /* yacc.c:1646  */
    {

		// add dataTypeDecln to type table

	}
#line 1461 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 116 "expl.y" /* yacc.c:1646  */
    {}
#line 1467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 119 "expl.y" /* yacc.c:1646  */
    {

		// install ID to type table
		Tinstall((yyvsp[-3].tnode_ptr) -> NAME, current_flist);
		struct Typetable *current_ttentry = Tlookup((yyvsp[-3].tnode_ptr) -> NAME);

		int fieldIndex = 0;

		printf("ID'ed data type %s\n", (yyvsp[-3].tnode_ptr) -> NAME);
		temp_flist = current_flist;
		if (temp_flist == NULL) {
			printf("current_flist is NULL.\n");
		}
		while (temp_flist != NULL) {
			// fix self-referential data types
			if (temp_flist -> type == NULL) {
				//printf("Type entry corresponding to variable %s was NULL, editing it now...\n", temp_flist -> name);
				temp_flist -> type = current_ttentry;
			}
			temp_flist -> fieldIndex = fieldIndex;
			fieldIndex++;
			printf("Stored variable %s of type %s with fieldIndex %d\n", temp_flist -> name, temp_flist -> type -> name, temp_flist -> fieldIndex);
			temp_flist = temp_flist -> next;
		}
		current_flist = NULL;	// because the next time code reaches here it will be a different type definition
		free(currently_defined_type);
		currently_defined_type = NULL;
	}
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 149 "expl.y" /* yacc.c:1646  */
    {
		if (currently_defined_type == NULL) {
			currently_defined_type = (char *) malloc(sizeof(char) * 30);
			strcpy(currently_defined_type, (yyvsp[0].tnode_ptr) -> NAME);
		}
		(yyval.tnode_ptr) = (yyvsp[0].tnode_ptr);
	}
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 157 "expl.y" /* yacc.c:1646  */
    {

		// add type_decln to fields list (current_flist)

	}
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 163 "expl.y" /* yacc.c:1646  */
    {

	}
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 168 "expl.y" /* yacc.c:1646  */
    {
		// check the ID corresponds to a data type in the type table
		struct Typetable *tt_entry = Tlookup((yyvsp[-2].tnode_ptr) -> NAME);
		/*printf("Looked up type %s\n", $1 -> NAME);
		if (tt_entry == NULL) {
			printf("Received NULL\n");
		}*/
		if (tt_entry == NULL && strcmp((yyvsp[-2].tnode_ptr) -> NAME, currently_defined_type) != 0) {
			printf("Line %d: undefined data type %s, exiting.\n", line_no + 1, (yyvsp[-2].tnode_ptr) -> NAME);
		}
		// temp_current_flist will not have the field 'type' initialized because this information
		// is available only now
		// so initialize the field
		temp_flist = temp_current_flist;
		while (temp_flist != NULL) {
			temp_flist -> type = tt_entry;	// if tt_entry is NULL it'll correspond to the fact that we're
			// dealing with a self-referential data type
			temp_flist = temp_flist -> next;
		}

		// add this list to the end of current_flist
		temp_flist = temp_current_flist;
		while (temp_flist != NULL && temp_flist -> next != NULL) {
			temp_flist = temp_flist -> next;
		}
		// the if (temp_current_flist == NULL) doesn't have to be checked because there will always be
		// at least one entry
		temp_flist -> next = current_flist;
		current_flist = temp_current_flist;

		temp_current_flist = NULL;

		/*temp_flist = current_flist;
		while (temp_flist != NULL) {
			if (tt_entry != NULL)
				printf("Assigning type %s to variable %s...\n", tt_entry -> name, temp_flist -> name);
			temp_flist -> type = tt_entry;	// if tt_entry is NULL it'll correspond to the fact that we're
			// dealing with a self-referential data type
			temp_flist = temp_flist -> next;
		}*/
	}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 211 "expl.y" /* yacc.c:1646  */
    {
		temp_current_flist = Finstall((yyvsp[0].tnode_ptr) -> NAME);
	}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 215 "expl.y" /* yacc.c:1646  */
    {
		temp_current_flist = Finstall((yyvsp[0].tnode_ptr) -> NAME);
	}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 222 "expl.y" /* yacc.c:1646  */
    {code_gen((yyvsp[0].tnode_ptr));}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 223 "expl.y" /* yacc.c:1646  */
    {}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 226 "expl.y" /* yacc.c:1646  */
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
			//printf("Stored parameter of name %s\n", temp_decln_arglist -> NAME);
			//printf("Its argument binding is %d\n", temp_decln_arglist -> ARG_SIM_BINDING);
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

		if ((yyvsp[-8].type_entry) != function_return_statement_type) {
			printf("Function %s returns value of incorrect type, exiting.\n", (yyvsp[-7].tnode_ptr) -> NAME);
			exit(0);
		}

		// actually generate the function code
		// name is needed to look up the local symbol table
		// $8 will have the slist for functions
		//printf("Creating tree for function definition of %s...\n", $2 -> NAME);
		(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_VOID, NODETYPE_FUNCTION_DEFINITION, -1, (yyvsp[-7].tnode_ptr) -> NAME, NULL, (yyvsp[-1].tnode_ptr), NULL, NULL, current_local_symbol_table, FALSE);

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
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 308 "expl.y" /* yacc.c:1646  */
    {

		}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 312 "expl.y" /* yacc.c:1646  */
    {

		}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 316 "expl.y" /* yacc.c:1646  */
    {}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 321 "expl.y" /* yacc.c:1646  */
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
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 332 "expl.y" /* yacc.c:1646  */
    {
			temp = check_if_already_defined(current_arg_list, (yyvsp[0].tnode_ptr) -> NAME);
			if (temp == 1) {
				printf("Arguments of the function declaration have the same name %s, exiting.\n", (yyvsp[0].tnode_ptr) -> NAME);
				exit(0);
			}
			// append ID to the beginning of the argument list
			current_arg_list = ArgInstall(current_arg_list, variable_type, (yyvsp[0].tnode_ptr) -> NAME, PASS_BY_REFERENCE);
		}
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 342 "expl.y" /* yacc.c:1646  */
    {
		temp = check_if_already_defined(current_arg_list, (yyvsp[0].tnode_ptr) -> NAME);
		if (temp == 1) {
			printf("Arguments of the function declaration have the same name %s, exiting.\n", (yyvsp[0].tnode_ptr) -> NAME);
			exit(0);
		}
		current_arg_list = ArgInstall(current_arg_list, variable_type, (yyvsp[0].tnode_ptr) -> NAME, PASS_BY_VALUE);
	}
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 351 "expl.y" /* yacc.c:1646  */
    {
		temp = check_if_already_defined(current_arg_list, (yyvsp[0].tnode_ptr) -> NAME);
		if (temp == 1) {
			printf("Arguments of the function declaration have the same name %s, exiting.\n", (yyvsp[0].tnode_ptr) -> NAME);
			exit(0);
		}
		current_arg_list = ArgInstall(current_arg_list, variable_type, (yyvsp[0].tnode_ptr) -> NAME, PASS_BY_REFERENCE);
	}
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 362 "expl.y" /* yacc.c:1646  */
    {

		printf("Processing main function...\n");
		// add main() to the global symbol table
		Ginstall("main", variable_type, 0, NULL, FALSE);
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

		struct Tnode *main_defn = TreeCreate(VAR_TYPE_VOID, NODETYPE_FUNCTION_DEFINITION, -1, "main", NULL, (yyvsp[-2].tnode_ptr), NULL, NULL, current_local_symbol_table, FALSE);
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
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 412 "expl.y" /* yacc.c:1646  */
    {}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 414 "expl.y" /* yacc.c:1646  */
    {}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 415 "expl.y" /* yacc.c:1646  */
    {}
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 418 "expl.y" /* yacc.c:1646  */
    {}
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 420 "expl.y" /* yacc.c:1646  */
    {
		// install this in the LOCAL symbol table for a function
		Linstall(current_local_symbol_table, (yyvsp[0].tnode_ptr) -> NAME, variable_type);
		printf("Installed local variable %s as type %s\n", (yyvsp[0].tnode_ptr) -> NAME, variable_type -> name);
	}
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 426 "expl.y" /* yacc.c:1646  */
    {
		Linstall(current_local_symbol_table, (yyvsp[0].tnode_ptr) -> NAME, variable_type);
		printf("Installed local variable %s as type %s\n", (yyvsp[0].tnode_ptr) -> NAME, variable_type -> name);
	}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 432 "expl.y" /* yacc.c:1646  */
    {
		// generate code for the function here
		// printf("Looking into the function body (code should be generated here)...\n");
		(yyval.tnode_ptr) = (yyvsp[-1].tnode_ptr);
	}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 439 "expl.y" /* yacc.c:1646  */
    {(yyval.tnode_ptr) = TreeCreate(NULL, NODETYPE_SLIST, -1, NULL, NULL, (yyvsp[-1].tnode_ptr), (yyvsp[0].tnode_ptr), NULL, current_local_symbol_table, FALSE);}
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 440 "expl.y" /* yacc.c:1646  */
    {(yyval.tnode_ptr) = (yyvsp[0].tnode_ptr);}
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 445 "expl.y" /* yacc.c:1646  */
    {}
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 447 "expl.y" /* yacc.c:1646  */
    {}
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 448 "expl.y" /* yacc.c:1646  */
    {}
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 453 "expl.y" /* yacc.c:1646  */
    {
		variable_type = Tlookup((yyvsp[0].tnode_ptr) -> NAME);
		(yyval.type_entry) = variable_type;
	}
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 459 "expl.y" /* yacc.c:1646  */
    {}
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 461 "expl.y" /* yacc.c:1646  */
    {
		printf("Global variable %s installed as %s\n", (yyvsp[0].tnode_ptr) -> NAME, variable_type -> name);
		Ginstall((yyvsp[0].tnode_ptr) -> NAME, variable_type, 1, NULL, FALSE);
	}
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 466 "expl.y" /* yacc.c:1646  */
    {
		printf("Installing array %s\n", (yyvsp[-3].tnode_ptr) -> NAME);
		(yyvsp[-1].tnode_ptr) -> TYPE = VAR_TYPE_INT;
		Ginstall((yyvsp[-3].tnode_ptr) -> NAME, variable_type, (yyvsp[-1].tnode_ptr) -> VALUE, NULL, TRUE);
	}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 472 "expl.y" /* yacc.c:1646  */
    {
		Ginstall((yyvsp[0].tnode_ptr) -> NAME, variable_type, 1, NULL, FALSE);
		printf("Global variable %s installed as %s\n", (yyvsp[0].tnode_ptr) -> NAME, variable_type -> name);
	}
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 477 "expl.y" /* yacc.c:1646  */
    {
		(yyvsp[-1].tnode_ptr) -> TYPE = VAR_TYPE_INT;
		Ginstall((yyvsp[-3].tnode_ptr) -> NAME, variable_type, (yyvsp[-1].tnode_ptr) -> VALUE, NULL, TRUE);
	}
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 482 "expl.y" /* yacc.c:1646  */
    {

			// function declaration

			Ginstall((yyvsp[-3].tnode_ptr) -> NAME, variable_type, 0, current_arg_list, FALSE);	// size is irrelevant here
			no_declared_functions++;
			// so is the SIM_BINDING field
			// but sim_binding value that's used must not be changed, hence the zero for the size
			current_arg_list = NULL;
			current_arg_binding	= 3;

		}
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 495 "expl.y" /* yacc.c:1646  */
    {

		Ginstall((yyvsp[-3].tnode_ptr) -> NAME, variable_type, 0, current_arg_list, FALSE);
		no_declared_functions++;
		current_arg_list = NULL;
		current_arg_binding	= 3;

	}
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 505 "expl.y" /* yacc.c:1646  */
    {
			//printf("Making ID node for %s\n", $1 -> NAME);
			(yyvsp[-3].tnode_ptr) -> ArgList = current_arg_list;
			(yyvsp[-3].tnode_ptr) -> Lentry = current_local_symbol_table;
			(yyvsp[-3].tnode_ptr) -> TYPE = find_id_type((yyvsp[-3].tnode_ptr));
			//printf("id type = %d\n", $1 -> TYPE);
			//printf("expr type = %d\n", $3 -> TYPE);
			if ((yyvsp[-3].tnode_ptr) -> TYPE != (yyvsp[-1].tnode_ptr) -> TYPE) {
				printf("Inconsistent types for assignment at line %d; exiting.\n", line_no + 1);
				exit(0);
			}
			(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_VOID, ASGN, -1, NULL, current_arg_list, (yyvsp[-3].tnode_ptr), (yyvsp[-1].tnode_ptr), NULL, current_local_symbol_table, FALSE);
		}
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 519 "expl.y" /* yacc.c:1646  */
    {
			(yyvsp[-6].tnode_ptr) -> ArgList = current_arg_list;
			(yyvsp[-6].tnode_ptr) -> Lentry = current_local_symbol_table;
			(yyvsp[-6].tnode_ptr) -> TYPE = find_id_type((yyvsp[-6].tnode_ptr));
			(yyvsp[-6].tnode_ptr) -> array_or_not = find_array_or_not((yyvsp[-6].tnode_ptr));
			if (!((yyvsp[-6].tnode_ptr) -> array_or_not)) {
				printf("Trying to index into a non-array variable %s of type %s; exiting.\n", (yyvsp[-6].tnode_ptr) -> NAME, (yyvsp[-6].tnode_ptr) -> TYPE -> name);
				exit(0);
			}
			// means ID is array alright
			// now we just have to check if expr is compatible with ID
			if ((yyvsp[-6].tnode_ptr) -> TYPE != (yyvsp[-1].tnode_ptr) -> TYPE) {
				printf("Inconsistent types for assignment; exiting.\n");
				exit(0);
			}
			struct Tnode *new_id_node = TreeCreate((yyvsp[-6].tnode_ptr) -> TYPE, ID, -1, (yyvsp[-6].tnode_ptr) -> NAME, NULL, (yyvsp[-4].tnode_ptr), NULL, NULL, current_local_symbol_table, FALSE);
			////printf("Making ID array node\n");
			(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_VOID, ASGN, -1, NULL, current_arg_list, new_id_node, (yyvsp[-1].tnode_ptr), NULL, current_local_symbol_table, FALSE);
		}
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 539 "expl.y" /* yacc.c:1646  */
    {
			(yyvsp[-2].tnode_ptr) -> ArgList = current_arg_list;
			(yyvsp[-2].tnode_ptr) -> Lentry = current_local_symbol_table;
			(yyvsp[-2].tnode_ptr) -> TYPE = find_id_type((yyvsp[-2].tnode_ptr));
			//printf("id type = %d\n", $3 -> TYPE);
			if ((yyvsp[-2].tnode_ptr) -> TYPE != VAR_TYPE_INT) {
 			 printf("READ variable is of incorrect type; exiting.\n");
 			 exit(0);
 		  }
			(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_VOID, READ, -1, NULL, current_arg_list, (yyvsp[-2].tnode_ptr), NULL, NULL, current_local_symbol_table, FALSE);
		}
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 551 "expl.y" /* yacc.c:1646  */
    {
			(yyvsp[-5].tnode_ptr) -> ArgList = current_arg_list;
			(yyvsp[-5].tnode_ptr) -> Lentry = current_local_symbol_table;
			(yyvsp[-5].tnode_ptr) -> TYPE = find_id_type((yyvsp[-5].tnode_ptr));
			(yyvsp[-5].tnode_ptr) -> array_or_not = find_array_or_not((yyvsp[-5].tnode_ptr));
			//printf("id type read = %d\n", $3 -> TYPE);
			// this is READ for arrays
			// reason why you can't have READ(expr) (similar to WRITE below)
			// is because READ can only read into VARIABLES (and not expressions).
			// e.g. any statements of the form read(a + b + c) (which is an expr) is
			// wrong, but write(a + b + c) works

			// but before all that check the type of variables
			if ((yyvsp[-5].tnode_ptr) -> TYPE != VAR_TYPE_INT || !(yyvsp[-5].tnode_ptr) -> array_or_not) {
				printf("Incorrect array type for READ statement; exiting.\n");
				exit(0);
			}
			if ((yyvsp[-3].tnode_ptr) -> TYPE != VAR_TYPE_INT) {
				printf("Incorrect index type for array; exiting.\n");
				exit(0);
			}
			struct Tnode *new_id_node = TreeCreate(NULL, ID, -1, (yyvsp[-5].tnode_ptr) -> NAME, NULL, (yyvsp[-3].tnode_ptr), NULL, NULL, current_local_symbol_table, FALSE);
			(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_VOID, READ, -1, NULL, current_arg_list, new_id_node, NULL, NULL, current_local_symbol_table, FALSE);
		}
#line 2066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 576 "expl.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-2].tnode_ptr) -> TYPE != VAR_TYPE_INT) {
 			 printf("WRITE variable is of incorrect type; exiting.\n");
 			 exit(0);
 		  }
			(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_VOID, WRITE, -1, NULL, current_arg_list, (yyvsp[-2].tnode_ptr), NULL, NULL, current_local_symbol_table, FALSE);
		}
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 584 "expl.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-5].tnode_ptr) -> TYPE != VAR_TYPE_BOOL) {
 			 printf("Incorrect type for if condition statement; exiting.\n");
 			 exit(0);
 		  }
			(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_VOID, IF, -1, NULL, current_arg_list, (yyvsp[-5].tnode_ptr), (yyvsp[-2].tnode_ptr), NULL, current_local_symbol_table, FALSE);
		}
#line 2090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 592 "expl.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-5].tnode_ptr) -> TYPE != VAR_TYPE_BOOL) {
 			 printf("Incorrect type for while loop condition; exiting.\n");
 			 exit(0);
 		  }
			(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_VOID, WHILE, -1, NULL, current_arg_list, (yyvsp[-5].tnode_ptr), (yyvsp[-2].tnode_ptr), NULL, current_local_symbol_table, FALSE);
		}
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 600 "expl.y" /* yacc.c:1646  */
    {
			(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_VOID, NODETYPE_RETURN_STMT, -1, NULL, current_arg_list, (yyvsp[-1].tnode_ptr), NULL, NULL, current_local_symbol_table, FALSE);
			function_return_statement_type = (yyvsp[-1].tnode_ptr) -> TYPE;
			no_return_statements++;
		}
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 608 "expl.y" /* yacc.c:1646  */
    {
		(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_VOID, NODETYPE_FUNCTION_ARG_LIST, -1, NULL, current_arg_list, (yyvsp[-2].tnode_ptr), (yyvsp[0].tnode_ptr), NULL, NULL, FALSE);
	}
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 612 "expl.y" /* yacc.c:1646  */
    {
		(yyval.tnode_ptr) = TreeCreate(VAR_TYPE_VOID, NODETYPE_FUNCTION_ARG_LIST, -1, NULL, current_arg_list, NULL, (yyvsp[0].tnode_ptr), NULL, NULL, FALSE);
	}
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 616 "expl.y" /* yacc.c:1646  */
    {}
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 619 "expl.y" /* yacc.c:1646  */
    {
		(yyval.tnode_ptr) = makeOperatorNode(PLUS, (yyvsp[-2].tnode_ptr), (yyvsp[0].tnode_ptr), current_local_symbol_table, current_arg_list);
	}
#line 2142 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 622 "expl.y" /* yacc.c:1646  */
    {(yyval.tnode_ptr) = makeOperatorNode(MUL, (yyvsp[-2].tnode_ptr), (yyvsp[0].tnode_ptr), current_local_symbol_table, current_arg_list);}
#line 2148 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 624 "expl.y" /* yacc.c:1646  */
    {(yyval.tnode_ptr) = makeOperatorNode(MINUS, (yyvsp[-2].tnode_ptr), (yyvsp[0].tnode_ptr), current_local_symbol_table, current_arg_list);}
#line 2154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 626 "expl.y" /* yacc.c:1646  */
    {(yyval.tnode_ptr) = makeOperatorNode(DIV, (yyvsp[-2].tnode_ptr), (yyvsp[0].tnode_ptr), current_local_symbol_table, current_arg_list);}
#line 2160 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 628 "expl.y" /* yacc.c:1646  */
    {(yyval.tnode_ptr) = TreeCreate((yyvsp[-1].tnode_ptr) -> TYPE, PARENS, -1, NULL, NULL, (yyvsp[-1].tnode_ptr), NULL, NULL, current_local_symbol_table, FALSE);}
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 630 "expl.y" /* yacc.c:1646  */
    {(yyvsp[0].tnode_ptr) -> TYPE = VAR_TYPE_INT; (yyval.tnode_ptr) = (yyvsp[0].tnode_ptr);}
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 632 "expl.y" /* yacc.c:1646  */
    {
		(yyvsp[0].tnode_ptr) -> Lentry = current_local_symbol_table;
 		(yyvsp[0].tnode_ptr) -> ArgList = current_arg_list;
		// since it can be assumed that this variable would already exist,
		// we can look it up and assign its type to it
		(yyvsp[0].tnode_ptr) -> TYPE = find_id_type((yyvsp[0].tnode_ptr));
    (yyval.tnode_ptr) = (yyvsp[0].tnode_ptr);
   }
#line 2185 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 641 "expl.y" /* yacc.c:1646  */
    {
		 // can be referencing an array
		 //printf("ID given array\n");
		 //printf("name = %s\n", $1 -> NAME);
		 (yyvsp[-3].tnode_ptr) -> ArgList = current_arg_list;
		 (yyvsp[-3].tnode_ptr) -> Lentry = current_local_symbol_table;
		 (yyvsp[-3].tnode_ptr) -> TYPE = find_id_type((yyvsp[-3].tnode_ptr));
		 (yyvsp[-3].tnode_ptr) -> array_or_not = find_array_or_not((yyvsp[-3].tnode_ptr));
		 if ((yyvsp[-1].tnode_ptr) -> TYPE != VAR_TYPE_INT) {
			 printf("Line %d: incorrect type for array index; exiting.\n", line_no + 1);
			 exit(0);
		 }
		 if (!(yyvsp[-3].tnode_ptr) -> array_or_not) {
			 printf("Trying to index into a non-array variable %s; exiting.\n", (yyvsp[-3].tnode_ptr) -> NAME);
			 exit(0);
		 }
		 (yyval.tnode_ptr) = TreeCreate((yyvsp[-3].tnode_ptr) -> TYPE, ID, -1, (yyvsp[-3].tnode_ptr) -> NAME, current_arg_list, (yyvsp[-1].tnode_ptr), NULL, NULL, current_local_symbol_table, FALSE);
	 }
#line 2208 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 660 "expl.y" /* yacc.c:1646  */
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
				 //printf("Line %d: checking %s against argument %s\n", line_no + 1, current_fn_args -> Ptr2 -> NAME, temp_current_arg_list -> NAME);
				 current_fn_args = current_fn_args -> Ptr1;
				 temp_current_arg_list = temp_current_arg_list -> NEXT;
			 }
		 }

		 if (temp_current_arg_list != NULL || current_fn_args != NULL) {
			 printf("temp_current_arg_list has value %s\n", temp_current_arg_list -> NAME);
			 printf("Incorrect number of arguments in function call %s at line %d, exiting.\n", (yyvsp[-3].tnode_ptr) -> NAME, line_no);
			 exit(0);
		 }

		 (yyval.tnode_ptr) = TreeCreate(function_call_lookup -> TYPE, NODETYPE_FUNCTION_CALL, -1, (yyvsp[-3].tnode_ptr) -> NAME, current_arg_list, (yyvsp[-1].tnode_ptr), NULL, NULL, current_local_symbol_table, FALSE);
		 //current_arg_list = NULL;
	 }
#line 2246 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 694 "expl.y" /* yacc.c:1646  */
    {
		 (yyval.tnode_ptr) = makeOperatorNode(LT, (yyvsp[-2].tnode_ptr), (yyvsp[0].tnode_ptr), current_local_symbol_table, current_arg_list);
	 }
#line 2254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 698 "expl.y" /* yacc.c:1646  */
    {
		 (yyval.tnode_ptr) = makeOperatorNode(GT, (yyvsp[-2].tnode_ptr), (yyvsp[0].tnode_ptr), current_local_symbol_table, current_arg_list);
	 }
#line 2262 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 702 "expl.y" /* yacc.c:1646  */
    {
		 (yyval.tnode_ptr) = makeOperatorNode(EQ, (yyvsp[-2].tnode_ptr), (yyvsp[0].tnode_ptr), current_local_symbol_table, current_arg_list);
	 }
#line 2270 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 706 "expl.y" /* yacc.c:1646  */
    {
		 (yyval.tnode_ptr) = makeOperatorNode(LE, (yyvsp[-2].tnode_ptr), (yyvsp[0].tnode_ptr), current_local_symbol_table, current_arg_list);
	 }
#line 2278 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 710 "expl.y" /* yacc.c:1646  */
    {
		 (yyval.tnode_ptr) = makeOperatorNode(GE, (yyvsp[-2].tnode_ptr), (yyvsp[0].tnode_ptr), current_local_symbol_table, current_arg_list);
	 }
#line 2286 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2290 "y.tab.c" /* yacc.c:1646  */
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
#line 715 "expl.y" /* yacc.c:1906  */


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
