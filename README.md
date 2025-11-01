// cJSON – Refatoração guiada por análise estática

Refatoração com foco em **segurança, legibilidade e manutenibilidade**.

// Mudanças principais:
- Substituição de `sprintf` → `snprintf` (prevenção de overflow)
- Criação da função comum `format_number()` (remove duplicação)
- `parse_value()` decomposta em helpers (`parse_*_value`)
- Adição de docstrings Doxygen nas APIs públicas

  Métricas (Antes × Depois)
| Métrica | Antes | Depois |
|----------|--------|--------|
| Complexidade média | 4.2 | 3.5 |
| Cobertura de testes | 83% | 86% |
| Dívida técnica | 3h40 | 2h10 |
| Código duplicado | 4.5% | 1.8% |

// Como rodar:
```bash
make test
cppcheck --enable=all .
lizard cJSON.c
