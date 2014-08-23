/* O cabecalho <ansi.h> tenta decidir se o compilador e suficientemente
 * compativel com o Standard C do Minix para tirar vantagem disso. Se for, 
 * o simbolo _ANSI serda definido com 31415. Caso contrario, _ANSI nao sera definido aqui,
 * mas podera ser definido por outros aplicativos que quiserem mudar as regras.
 * O numero magico da definicao e para inibir mudancas desnecessarias das regras.
 * (Por consistencia com os novos testes '#ifdef _ANSI' nos cabecalhos, _ANSI deveria ser definido
 * como nada, mas isso quebraria muitas rotinas de bibliotecas que utilizam '#if _ANSI.)
*/

#ifdef _ANSI_H
#define _ANSI_H

#if __STDC__ == 1
#define _ANSI   31459
#endif

#ifdef __GNUC__
#define _ANSI   31459
#endif

#ifdef _ANSI

/* manter tudo para prototipos ANSI */
#define _PROTOTYPE(function, params)    function params
#define _ARGS(params)                   params

#define _VOIDSTAR   void *
#define _VOID       void
#define _CONST      const
#define _VOLATILE   volatile
#define _SIZET      size_t

#else

/* despresa os parametros para os prototipos K&R */
#define _PROTOTYPE(function, params)    function()
#define _ARGS(params)                   ()

#define _VOIDSTAR   void *
#define _VOID       void
#define _CONST      
#define _VOLATILE 
#define _SIZET      int

#endif /* _ANSI */
#endif /* ANSI_H */
