# ���������� ����-�����
������� �������, ������� 1 ����� ���� ���� 

## �������� �������
������ ������������ ����� ����������, ������� ��������� ����� ���������, ���������� �� ��� �����, � ��� ��� ����������� ���� ��������� ����������. 

## ������ � ������
*��������� �������� ��� ������� Windows.*

### ������ �������:

1. ���������� �����������
```bash
$ git clone https://github.com/71frukt/PUNK_LANGUAGE.git
```

2. �������� ������
```bash
$ make
```

### ������ � ������ ����� ���������

1. ������
```bash
$ compile <your_code_file> <asm_file>
```

<details>
<summary>��� ������� frontend, middlend � backend ������ �� �����������</summary>

```bash
$ cd frontend/build
$ frontend.exe <input_file> <output_file>
$ cd ../..
```

```bash
$ cd middlend/build
$ middlend.exe <input_file> <output_file>
$ cd ../..
```

```bash
$ cd backend/build
$ backend.exe <input_file> <output_file>
$ cd ../..
```

</details>
<br>

2. ������
```bash
$ run <asm_file>
```

## ��������� �����
### 1. ����� �������
����� ��������� ����� �� ���������� ����� ��. �������� ������:
* � ��������� ������ ������������ ������� ������� `MAIN_HOI`, � ������� �������� � ���������� ���������� ���������.
* ��� �������� �������� ����� ������ ��� - `int`.
* ������� ����� ��������� �������������� ���������� ����������.
* ����� ���������� ������ ���� �� ���������� �����
* ����� �� �� ���������� ����� � �� ���������� ��������� ��������� �������������

����-���� ������ ������ �������� �����, ��� ��������� ������������ � ���������� ��������, ��������� ������ ������� � ������� ���������. ��� ������� ����� - ����� ����, ������������ ��������� �������� � �� ��� ���������������� �� ������������ ������� � ����-����� - �������� ���� ������� ���. ��� ��������� ��������� ��������� ���������� � ������ ������ ���� � �������� �� ���������.

### 2. ���������
��������� ����� ������� �� ��� ���������: �������� �����, ����������� ����� � �������������� ���������.

### �������� �����

|����� � ����-����� | ������ � �� | 
|-------------------|-------------|
| �����             |    int      |
| ���               |      ;      |
| ������            |      ,      |
| ������            |      =      |
| ����              |     if      |
| ����              |    while    |
| ���               |    return   |
| �������           |    scanf    |
| ������            |    printf   |

### ����������� �����
|����� � ����-����� | ������ � �� | 
|-------------------|-------------|
| �����_���         |      {      |
| �����_������      |      }      |
| �������           |      (      |
| ��������          |      )      |

### �������������� ��������

| ����� � ����-�����  | ������ � �� |
|---------------------|-------------|
| �����               | ==          |
| ��_�����            | !=          |
| ���������           | <           |
| ������              | >           |
| ������              | +           |
| �����               | -           |
| �������             | *           |
| �������             | /           |
| �������             | sqrt        |
| ��������            | pow         |
| ����������          | ln          |


## ������ ���������
### ���������