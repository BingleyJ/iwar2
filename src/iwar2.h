

#ifdef HAVE_CONFIG_H
#include "config.h"             /* From autoconf */
#endif

#include <stdint.h>

typedef char sbool;     /* From rsyslog. 'bool' causes compatiablity problems on OSX. "(small bool) I intentionally use char, to keep it slim so that many fit into the CPU cache!".  */

#ifndef HAVE_STRLCPY
int strlcpy(char *, const char *,  size_t );
#endif

#ifndef HAVE_STRLCAT
int strlcat(char *, const char *, size_t );
#endif

typedef struct _iWarConfig _iWarConfig;
struct _iWarConfig {

    sbool	 daemonize; 
    sbool	 serial_flag;

    char	 iwar_config_file[255]; 

    char	 iwar_predial[128];
    char	 iwar_mask[30];
    uint64_t	 iwar_start;
    uint64_t	 iwar_end;
};

typedef struct _iWarVar _iWarVar;
struct _iWarVar {
     char var_name[64]; 
     char var_value[64];
};

typedef struct _iWarCounters _iWarCounters;
struct _iWarCounters {

	int iwars_count; 
	int iwarm_count;

	int var_count;

	int serial_count;

	int max_row; 
	int max_col;

};

typedef struct _iWarS _iWarS;
struct _iWarS {
        char command[512];
};

void  iWar_Mainscreen( void );
void  iWar_Testscreen( void );
void  iWar_Intro( void );
void  iWar_Display_Info(const char *, int, int);
char *iWar_Mask_Replace(char *, char *) ;
void  iWar_Usage( void );
char  *iWar_Remove_Return(char *);
void  iWar_Load_Config( void );
char *iWar_Between_Quotes(char *);
char *iWar_Replace_Str(char *, char *, char *);
char *iWar_Var_To_Value(char *);
void iWar_Mother_Forker ( void ); 