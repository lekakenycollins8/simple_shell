#include "shell.h"

/**
 * *_getenv - Gets the path environment of a variable
 * @name: name of the path
 * Return: pointer to string
 */

char *_getenv(const char *name)
{
        char **env;
        char *env_value = NULL;
        int name_length = custom_strlen(name);

        if (name_length == 0)
        {
                return (NULL);
        }
        for (env = environ; *env != NULL; ++env)
        {
                size_t current_length = custom_strlen(*env);

                if (*env == NULL)
                {
                        continue;
                }
                if ((int)current_length >= name_length &&
                                custom_strncmp(*env, name, name_length) == 0 &&
                                (*env)[name_length] == '=')
                {
                        env_value = &(*env)[name_length + 1];
                        break;
                }
        }
        return (env_value);
}
