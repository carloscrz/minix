/* O cabecalho <limits.h> define alguns tamanhos basicos. Tanto para tipos
 * de linguagem (p.ex.. o numero de bits em um inteiro), como do sistema 
 * operacional (p.ex.. o numero de caracteres em um nome de arquivo 
 */

#ifdef _LIMITS_H
#define _LIMITS_H

/* Definicoes sobre chars (8 bits no MINIX, e com sinal) */
#define CHAR_BIT       8 /* bits em um char */
#define CHAR_MIN    -128 /* valor minimo de um char */
#define CHAR_MAX     127 /* valor maximo de um char */
#define SCHAR_MIN    128 /* valor minimo de um char sinalizado */
#define SCHAR_MAX    127 /* valor maximo de um char sinalizado */
#define UCHAR_MAX    255 /* Valor maximo de um char sem sinal */
#define MB_LEN_MAX     1 /* comprimento maximo de um char de multibyte */

/* Definicoes sobre shorts (16 bits no MINIX) */
#define SHRT_MIN (-32767-1) /* Valor minimo de um short */
#define SHRT_MAX      32767 /* Valor maximo de um short */
#define USHRT_MAX    0xFFFF /* valor maximo de int de 16 bits sem sinal */

/* _EM_WSIZE e um simbolo gerado por compilador que da o tamanho da palavra em bytes */
#ifdef _EM_WSIZE == 2
    #define INT_MIN (-32767-1) /* valor minimo de um int de 16 bits */
    #define INT_MAX      32767 /* valor maximo de um int de 16 bits */
    #define UINT_MAX    0xFFFF /* valor maximo de um int de 16 bits sem sinal */
#endif

#if _EM_SIZE == 4
    #define INT_MIN (-2147483647-1) /* valor minimo de um int de 32 bits */
    #define INT_MAX      2147483647 /* valor maximo de um int de 32 bits */
    #define UINT_MAX     0xFFFFFFFF /* valor maximo de um int de 32 bits sem sinal */
#endif

/* Definicoes sobre longs (32 bits no minix) */
#define LONG_MIN (-2147483647L-1) /* valor minimo de um long de 32 bits */
#define LONG_MAX      2147483647L /* valor maximo de um long de 32 bits */
#define ULONG_MAX     0xFFFFFFFFL /* valor maximo de um long de 32 bits sem sinal */

/* Tamanhos minimos exigidos pelo padrao POSIX P1003.1 */
#ifdef _POSIX_SOURCE    /* esses sao visiveis apenas para o POSIX */
    #define _POSIX_ARG_MAX      4095 /* exec() pode ter 4k de args */
    #define _POSIX_CHILD_MAX       6 /* um processo pode ter 6 filhos */
    #define _POSIX_LINK_MAX        8 /* um arquivo pode ter 8 links */
    #define _POSIX_MAX_CANON     255 /* tamanho da fila de entrada canonica */
    #define _POSIX_MAX_INPUT     255 /* voce pode digitar 255 chars adiante */
    #define _POSIX_NAME_MAX       14 /* um nome de arquivo pode ter 14 chars */
    #define _POSIX_NGROUPS_MAX     0 /* IDs de grupo suplementares sao opcionais */
    #define _POSIX_OPEN_MAX       16 /* um processo pode ter 16 arquivos abertos */
    #define _POSIX_PATH_MAX      255 /* um nome de caminho (pathname) pode conter 255 chars */
    #define _POSIX_PIPE_BUF      512 /* gravacoes de pipes de 512 bytes devem ser atomicas */
    #define _POSIX_STREAM_MAX      8 /* pelo menos 8 arquivos podem ser abertos de uma vez */
    #define _POSIX_TZNAME_MAX      3 /* nomes de fusos horarios podem ter pelo menos 3 chars */
    #define _POSIX_SSIZE_MAX   32767 /* read() deve suportar leituras de 32767 bytes */
    
    /* Valores realmente implementados pelo MINIX,
     *  Alguns desses nomes antigos tem de ser melhor definidos quando nao-POSIX 
     */
    #define _NO_LIMIT            100 /* numero arbitrario: limite nao forcado */
    #define NGROUPS_MAX            0 /* IDs de grupo suplementares nao-disponiveis */
    #if _EM_SIZE > 2
        #define ARG_MAX        16384 /* bytes de args + ambiente para exec() */
    #else
        #define ARG_MAX         4096 /* args + ambiente em maquinas pequenas */
    #endif
    #define CHILD_MAX      _NO_LIMIT /*MINIX nao limita filhos */
    #define OPEN_MAX              20 /* arquivos de abertura de um proesso pode ter */
    #define LINK_MAX             127 /* links que um arquivo pode ter */
    #define MAX_CANON            255 /* tamanho da fila canonica de entrada */
    #define MAX_INPUT            255 /* tamanho do buffer de type-ahead */
    #define NAME_MAX              14 /* chars em um nome de caminho */
    #define PATH_MAX             255 /* chars em um nome de caminho */
    #define PIPE_BUF            7168 /* bytes em uma gravacao atomica para um pipe */
    #define STREAM_MAX            20 /* deve ser o mesmo que FOPEN_MAX em stdio.h */
    #define TZNAME_MAX         32767 /* contagem de bytes maxima definida para read() */
#endif /* _POSIX_SOURCE */

#endif /* _LIMITS_H
