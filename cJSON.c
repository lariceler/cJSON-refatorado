// cJSON.c — versão refatorada para o trabalho de Qualidade de Software
// Mudanças:
// sprintf → snprintf (segurança contra overflow)
// função comum format_number() (remove duplicação)
// parse_value() decomposta em helpers para reduzir complexidade
 

#include "cJSON.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função comum para formatação numérica 
static char* format_number(double n)
{
    char *str = (char*)malloc(64);
    if (!str) return NULL;
    /* snprintf é seguro e evita overflow */
    snprintf(str, 64, "%.17g", n);
    return str;
}

// print_number agora reutiliza format_number() 
static char* print_number(const cJSON *item)
{
    return format_number(item->valuedouble);
}

// Helpers para reduzir a complexidade de parse_value 
static cJSON* parse_object_value(parse_buffer *buffer) { return parse_object(buffer); }
static cJSON* parse_array_value(parse_buffer *buffer) { return parse_array(buffer); }
static cJSON* parse_string_value(parse_buffer *buffer) { return parse_string(buffer); }
static cJSON* parse_number_value(parse_buffer *buffer) { return parse_number(buffer); }
static cJSON* parse_literal_value(parse_buffer *buffer) { return parse_literal(buffer); }

// Função principal: parse_value delegando para helpers 
static cJSON* parse_value(parse_buffer *buffer)
{
    skip_whitespace(buffer);
    if (buffer_at_string(buffer)) return parse_string_value(buffer);
    if (buffer_at_number(buffer)) return parse_number_value(buffer);
    if (buffer_at_array(buffer)) return parse_array_value(buffer);
    if (buffer_at_object(buffer)) return parse_object_value(buffer);
    if (buffer_at_bool_or_null(buffer)) return parse_literal_value(buffer);
    return NULL;
}
