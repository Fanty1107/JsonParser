# JSON to TXT Parser

Um analisador (parser) genérico de arquivos JSON desenvolvido em C++ puro, sem a utilização de bibliotecas externas. O programa lê um arquivo estruturado em formato JSON via linha de comando, processa seus dados dinamicamente com base em padrões de sintaxe e exporta o conteúdo limpo e formatado para um arquivo de texto (.txt).

## Como Funciona
O programa recebe o caminho do arquivo JSON como argumento de inicialização (argv), evitando caminhos fixos (hardcoded) no código.
Varre o arquivo linha por linha identificando delimitadores chave do padrão JSON (aspas e dois-pontos) para separar chaves de seus respectivos valores.
Remove caracteres de sintaxe estrutural do JSON (como aspas duplas, vírgulas, chaves e colchetes) antes de gravar a informação final.
Converte blocos de objetos aninhados em cabeçalhos de seção e padroniza a escrita no formato Chave: Valor.


## Como Executar
```bash
./nome_do_executavel [caminho_do_arquivo.json]
```
