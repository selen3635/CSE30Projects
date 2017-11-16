/*
 * Filename: pa4Strings.h
 * Author:   Xiaolong Zhou
 * Userid:   cs30xaeo
 * Description: Strings used in PA4 output.
 * Date:  May 22, 2016
 * Sources of Help: Given.
 */

#ifndef PA4_STRINGS_H
#define PA4_STRINGS_H

/*
 * Usage strings
 */
#define STR_USAGE_SHORT "Usage: %s [-ahlrtBF] [file ...]\n"

#define STR_USAGE_LONG "Usage: %s [-ahlrtBF] [file ...]\n"\
  "List information about the files (the current directory by default).\n"\
  "Sort entries alphabetically if -t is not specified.\n\n"\
  "  -a, --all             do not ignore entries starting with .\n"\
  "  -l,                   use a long listing format\n"\
  "  -r, --reverse         reverse order while sorting\n"\
  "  -t,                   sort by modification time, newest first\n"\
  "  -B, --ignore-backups  do not list implied entries ending with ~\n"\
  "  -F, --classify        append indicator (one of */=>@|) to entries\n"\
  "\n"\
  "  -h, --help            displays this help and exit\n\n"

/*
 * getopt() strings
 */
#define ARG_STR "ahlrtBF"

/* Short options */
#define CHAR_A_FLAG 'a'
#define CHAR_H_FLAG 'h'
#define CHAR_L_FLAG 'l'
#define CHAR_R_FLAG 'r'
#define CHAR_T_FLAG 't'
#define CHAR_B_FLAG 'B'
#define CHAR_F_FLAG 'F'

/* Long options */
#define STR_A_LONG "all"
#define STR_H_LONG "help"
#define STR_R_LONG "reverse"
#define STR_B_LONG "ignore-backups"
#define STR_F_LONG "classify"


/*
 * Error strings
 */
#define STR_LSTAT_ERR    "lstat --"
#define STR_OPENDIR_ERR  "opendir --"
#define STR_PARTIAL_INFO "Only partial info will be displayed.\n"
#define STR_ALLOC_ERR    "Attempted to allocate memory in buildFileInfoTable()"


/*
 * Output strings
 */
#define STR_DIR_LABEL "%s:\n"
#define STR_BUILD_PATHNAME "%s/%s"
#define STR_NLINK "%3lu "
#define STR_MAJOR_MINOR "%3ld %3ld "
#define STR_SIZE "%7ld "
#define STR_GNAME "%-8s "
#define STR_GID "%-8ld "
#define STR_PWNAME "%-8s "
#define STR_UID "%-8u "

#endif /* PA4_STRINGS_H */
