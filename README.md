# ED1 — TAD Lista — LinkedList

Implementação de uma **Lista Encadeada Simples (LinkedList)** utilizando C++ e conceitos de **Tipo Abstrato de Dados (TAD)**.

O projeto apresenta uma separação entre:

- **Interface abstrata:** define o contrato da lista (`List.h`).
- **Implementação:** utiliza nós alocados dinamicamente, com ponteiros `head` e `tail`.
- **Testes:** validam as principais operações disponibilizadas pela lista.

> Instituto Federal do Triângulo Mineiro — Campus Patrocínio  
> Curso: Tecnologia em Análise e Desenvolvimento de Sistemas — 3º Período  
> Disciplina: Estrutura de Dados I  
> Professor: Júnio Moreira  
> Data: __/__/2026

---

## 📁 Estrutura do Projeto

```text
ed1_linked_list_cpp/
├── include/
│   ├── LinkedList.h
│   └── List.h
├── src/
│   └── LinkedListTest.cpp
├── .gitignore
├── CMakeLists.txt
├── main.cpp
└── README.md
```

## ⚙️ Operações e Complexidade

| Operação            | Complexidade                         |
|---------------------|--------------------------------------|
| `add`               | O(1) (graças ao ponteiro `tail`)     |
| `insert`            | O(1) no início/fim, O(n) no meio     |
| `remove`            | O(1) no início, O(n) nos demais      |
| `get` / `set`       | O(n)                                 |
| `indexOf`/`contains`| O(n)                                 |
| `size` / `isEmpty`  | O(1)                                 |
| `clear`             | O(n)                                 |

## 🔄 ArrayList × LinkedList

| Aspecto            | ArrayList                  | LinkedList                  |
|--------------------|----------------------------|-----------------------------|
| Memória            | Bloco contíguo             | Nós dispersos + ponteiros   |
| Acesso por índice  | O(1)                       | O(n)                        |
| Inserção no início | O(n) (deslocamento)        | O(1)                        |
| Capacidade         | Limitada/fixa              | Cresce dinamicamente        |

## ▶️ Como compilar e executar

```bash
cmake -S . -B build
cmake --build build
./build/ed1_linked_list_cpp
```