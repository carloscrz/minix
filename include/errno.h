/* O cabecalho <errno.h> define os codigos dos varios erros que podem ocorrer
 * durante a execucao do programa. Eles sao visiveis para programas do usuario
 * e devem ser inteiros pequenos positivos. Porem, eles tambem sao usados no MINIX
 * onde devem ser negatigos. Por exemplo, a chamada de sistema READ e executada
 * internamente chamando do_read(). Essa funcao retorna tanto um codigo de erro
 * (negativo) como o numero de bytes (positivo) realmente lidos.

 * Para resolver o problema de ter os codigos de erro negativos dentro do sistema
 * e positivos fora dele, o segunte mecanismo e utilizado. 
 * Todas as definicoes sao na forma:
 *
 *  #define EPERM (_SIGN 1)
 *
 * Se a macro _SYSTEM foi definida, entao _SIGN e configurada como "-", caso contrario
 * ela sera configurada como "". Assim, ao compilar o sistema operacional, a macro 
 * _SYSTEM sera definida, configurando EPERM como (-1), ao passo que quando esse arquivo
 * e incluido em um programa de usuario comum, EPERM tem o valor (1)
 */

#ifndef _ERRNO_H
#define _ERRNO_H

/* Definir _SIGN como "" ou "-" dependendo de _SYSTEM */
#ifdef _SYSTEM
    #define _SIGN   -
    #define OK      0
#else
    #define _SIGN
#endif

extern int errno;   /* o lugar onde os codigos de erro entram */

/* aqui estao os valores numericos dos codigos de erro */
#define _NERROR                 70 /* numero de erros */
#define EGENERIC        (_SIGN 99) /* erro generico */
#define EPERM           (_SIGN  1) /* operacao nao permitida */
#define ENOENT          (_SIGN  2) /* nao existe tal arquivo ou diretorio */
#define ESRCH           (_SIGN  3) /* nao existe tal processo */
#define EINTR           (_SIGN  4) /* interrompida a chamada de funcao */
#define EIO             (_SIGN  5) /* erro de entrada/saida */
#define ENXIO           (_SIGN  6) /* nao existe tal dispositivo ou endereco */
#define E2BIG           (_SIGN  7) /* lista de arg muito granda */
#define NOEXEC          (_SIGN  8) /* erro no formato de exec */
#define EBADF           (_SIGN  9) /* descritor de arquivo improprio */
#define ECHILD          (_SIGN 10) /* sem processo filho */
#define EGAIN           (_SIGN 11) /* recurso temporariamente indisponivel */
#define ENOMEM          (_SIGN 12) /* sem espaco suficiente */
#define EACCES          (_SIGN 13) /* permissao negada */
#define EFAULT          (_SIGN 14) /* endereco improprio */
#define ENOTBLK         (_SIGN 15) /* extencao: nao e um arquivo especial de bloco */
#define EBUSY           (_SIGN 16) /* recurso ocupado */
#define EEXIST          (_SIGN 17) /* arquivo ja existe */
#define EXDEV           (_SIGN 18) /* link improprio */
#define ENODEV          (_SIGN 19) /* nao existe tal dispositivo */
#define ENOTDIR         (_SIGN 20) /* nao e diretorio */
#define EISDIR          (_SIGN 21) /* e um diretorio */
#define EINVAL          (_SIGN 22) /* argumento invalido */
#define ENFILE          (_SIGN 23) /* arquivos abertos demais no sistema */
#define EMFILE          (_SIGN 24) /* arquivos abertos demais */
#define ENOTTY          (_SIGN 25) /* operacao de controle de E/S impropria */
#define ETXTBSY         (_SIGN 26) /* nao mais utilizado */
#define EFBIG           (_SIGN 27) /* arquivo muito grande */
#define ENOSPC          (_SIGN 28) /* sem mais espaco no dispositivo */
#define ESPIPE          (_SIGN 29) /* busca invalida */
#define EROFS           (_SIGN 30) /* sistema de arquivo so de leitura */
#define EMLINK          (_SIGN 31) /* links demais */
#define EPIPE           (_SIGN 32) /* pipe quebrado */
#define EDOM            (_SIGN 33) /* erro de dominio (do ANSI C std) */
#define ERANGE          (_SIGN 34) /* resultado muito grande (do ANSI C std) */
#define EDEADLK         (_SIGN 35) /* impasse de recurso evitado */
#define ENAMETOOLONG    (_SIGN 36) /* nome de arquivo muito longo */
#define ENOLCK          (_SIGN 37) /* nenhum bloqueio disponivel */
#define ENOSYS          (_SIGN 38) /* funcao nao-implementada */
#define ENOTEMPTY       (_SIGN 39) /* diretorio nao esta vazio */

/* os seguintes erros relacionam-se com a rede */
#define EPACKSIZE       (_SIGN 50) /* tamanho de pacote invalido para algum protocolo */
#define EOUTOFBUFS      (_SIGN 51) /* nao foram deixados buffers suficientes */
#define EBADIOCTL       (_SIGN 52) /* ioctl ileal para dispositivo */
#define EBADMODE        (_SIGN 53) /* badmode ioctl */
#define EWOULDBLOCK     (_SIGN 54)
#define EBADDEST        (_SIGN 55) /* nao e endereco valido de destino */
#define EDSTNOTRCH      (_SIGN 56) /* destino nao-acessavel */
#define EISCONN         (_SIGN 57) /* tudo pronto e conectado */
#define EADDRINUSE      (_SIGN 58) /* endereco em uso */
#define ECONNREFUSED    (_SIGN 59) /* conexao recusada */
#define ECONNRESET      (_SIGN 60) /* conexao reconfigurada */
#define ETIMEDOUT       (_SIGN 61) /* conexao atingiu tempo limite */
#define EURG            (_SIGN 62) /* dados urgentes presentes */
#define ENOURG          (_SIGN 63) /* sem dados urgentes presentes */
#define ENOTCONN        (_SIGN 64) /* sem conexao (ainda ou nunca mais) */
#define ESHUTDOWN       (_SIGN 65) /* uma chamada write para derrubar uma conexao */
#define ENOCONN         (_SIGN 66) /* nao existe tal conexao */

/* os seguintes nao sao erros POSIX, mas ainda podem acontecer */
#define ELOCKED        (_SIGN 101) /* nao pode enviar mensagem */
#define EBADCALL       (_SIGN 102) /* erro no envio/recebimento  */

/* os seguintes codigos de erro sao gerados pelo proprio kernel */
#ifdef _SYSTEM
#define E_BAD_DEST      -1001 /* endereco de destino ilegal */
#define E_BAD_SRC       -1002 /* endereco de origem ilegal */
#define E_TRY_AGAIN     -1003 /* nao pode enviar tabelas completas */
#define E_OVERRUN       -1004 /* interrompe para tarefe que nao esta operando */
#define E_BAD_BUF       -1005 /* buffer de mensagem fora do espaco de enderecamento da chamada */
#define E_TASK          -1006 /* nao pode enviar para tarefa */
#define E_NO_MESSAGE    -1007 /* RECEIVE falhou: nenhuma mensagem presente */
#define E_NO_PERM       -1008 /* usuarios normais nao podem enviar para tarefas */
#define E_BAD_FCB       -1009 /* as unicas funcoes validas sao SEND, RECEIVE, BOUTH */
#define E_BAD_ADD       -1010 /* endereo improprio passado para rotina utilitaria */
#define E_BAD_ORIC      -1011 /* nome de proc improprio passado para utilitario */

#endif /* _SYSTEM */
#endif /* _ERRNO_H */
