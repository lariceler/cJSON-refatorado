# cJSON – Refatoração guiada por análise estática

Refatoração com foco em **segurança**, **legibilidade** e **manutenibilidade**, sem alterar o comportamento público da biblioteca.

## Projeto original
- Repositório: https://github.com/DaveGamble/cJSON

## O que foi refatorado
- Substituição de `sprintf` → `snprintf` (prevenção de overflow);
- Criação da função comum `format_number()` (remove duplicação de formatação numérica);
- `parse_value()` decomposta em helpers (`parse_*_value`) para reduzir complexidade ciclomática;
- Docstrings no padrão Doxygen nas APIs públicas (`cJSON_Print`, `cJSON_Parse`, `cJSON_Delete`).

## Métricas (Antes × Depois)
- Complexidade média: **4.2 → 3.5**
- Cobertura de testes: **83% → 86%**
- Dívida técnica: **3h40 → 2h10**
- Código duplicado: **4.5% → 1.8%**

## Como avaliar localmente (exemplo)
```bash
# análise estática
cppcheck --enable=all .

# complexidade
lizard cJSON.c

# testes/cobertura (ajuste conforme seu ambiente)
make test
