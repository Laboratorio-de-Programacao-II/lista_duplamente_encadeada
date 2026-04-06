#!/bin/bash
echo "Executando testes ..."
echo

# Variáveis para contagem de resultados
PASS=0
FAIL=0

# Executa o programa para cada caso de teste na pasta input/
for input_file in input/*; do
    filename=$(basename "$input_file")
    expected_file="output/$filename"

    # Verifica se o arquivo de saída esperado existe
    if [ ! -f "$expected_file" ]; then
        echo "ERRO: Arquivo de saída esperado não encontrado: $expected_file"
        exit 1
    fi

    # Executa o programa com o arquivo de entrada e captura a saída
    actual=$(./prog < "$input_file")
    exit_code=$?

    # Verifica se o programa saiu com código zero
    if [ $exit_code -ne 0 ]; then
        echo "ERRO: Programa encerrou com código diferente de 0"
        FAIL=$((FAIL + 1))
        continue
    fi

    # Compara a saída real com a saída esperada
    expected=$(cat "$expected_file")
    if [ "$actual" = "$expected" ]; then
        echo "Teste $filename: Saída correta"
        PASS=$((PASS + 1))
    else
        echo "Teste $filename: Saída incorrecta"
        echo "-- Esperado:"
	echo "$expected"
        echo "-- Obtido:" 
	echo "$actual"
        FAIL=$((FAIL + 1))
    fi
done

# Resumo dos testes
echo ""
echo "Resultado testes: $PASS corretos, $FAIL errados."

if [ $FAIL -eq 0 ]; then
    echo "Todos os testes corretos!"
    exit 0
else
    echo "Existem testes incorretos!"
    exit 1
fi
