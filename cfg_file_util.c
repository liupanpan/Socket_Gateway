#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
   char * str;
   ssize_t ret = -1;
   if ((NULL == *lineptr) || (0 == *n))
   {
      *lineptr = malloc(256);
      *n = 256;
   }

   if (*lineptr)
   {
      str = fgets(*lineptr, *n, stream);
      if (str)
      {
         ret = strlen(str);
      }
   }
   return ret;
}

char const * Get_Config_String_From_File(char const *default_value, char const *file_name)
{
   FILE* file = NULL;
   char const *config_value = NULL;
   bool_t use_default = true;

   if (NULL == default_value)
   {
      default_value = "";
   }

   if (NULL != file_name)
   {
      file = fopen(file_name, "r");
   }

   if (file != NULL)
   {
      char * line = NULL;
      size_t line_size = 0;

      /* Read until the end of the file to find the first actual line of the file */
      while (-1 != getline(&line, &line_size, file))
      {
         size_t i = 0;

         /* Find the first character of this line */
         for (i = 0; (isspace((int) line[i] & 0xff) && i < line_size); i++)
         {
            /* work done in loop construct above */
         }

         /* Is this a comment line? */
         if (line[i] != '#')
         {
            char * config_string = &line[i];

            size_t len = strlen(config_string);

            /* Strip trailing '\n', if present */
            if ((len > 0) && ('\n' == config_string[len - 1]))
            {
               len--;
               config_string[len] = '\0';
            }

            if (len > 0)
            {
               config_value = strdup(config_string); /* use contents of file for address */
               use_default = false;
               break; /* Exit the while loop and terminate search */
            }
         }
         free(line);
         line = NULL;
      }
      free(line);
      fclose(file);
   }

   if (use_default)
   {
      config_value = strdup(default_value);
   }

   return config_value; /* Caller responsible for freeing memory! */
}

void Free_Config_String(char const ** config_string)
{
   free((char *) *config_string);
   *config_string = NULL;
}
