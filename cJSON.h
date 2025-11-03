#ifndef cJSON__h
#define cJSON__h

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

/**
 * @brief Converte um nó cJSON em uma string alocada dinamicamente.
 * @param item Nó cJSON a ser serializado.
 * @return Ponteiro para string recém-alocada (use cJSON_free para liberar), ou NULL em erro.
 */
CJSON_PUBLIC(char *) cJSON_Print(const cJSON *item);

/**
 * @brief Analisa uma string JSON e retorna a árvore cJSON resultante.
 * @param value String JSON de entrada (terminada em '\0').
 * @return Raiz cJSON ou NULL em caso de erro de parsing.
 */
CJSON_PUBLIC(cJSON *) cJSON_Parse(const char *value);

/**
 * @brief Libera recursivamente a árvore cJSON.
 * @param item Raiz (ou subárvore) a ser liberada.
 */
CJSON_PUBLIC(void) cJSON_Delete(cJSON *item);

#ifdef __cplusplus
}
#endif

#endif
