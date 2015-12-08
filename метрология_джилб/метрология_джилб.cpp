#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#define N 23

int main ()
{
	int i = 0;
	int massive[10];
	int number_of_operator_if = 0;
	int total_number_of_operators = 0;
	int maximum_level_of_nesting = 0;
	int position_if_in_file = 0;
	char string_from_a_file[100];
	char *pointer_in_a_string;
	char operator_if[3] = "if";
	char operator_begin[6] = "begin";
	char operator_end[4] = "end";
	float result;
	
	struct Delphi
	{
		char current_string[10];
	};

	struct Delphi operators[N];

	FILE *All_Operators;
	All_Operators = fopen("All_Operators.txt","rt");
	while (!feof(All_Operators))
	{
		fscanf (All_Operators, "%s", &operators[i].current_string);
		i++;	
	}
	fclose(All_Operators);


	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	FILE *Jilba;
	Jilba = fopen("Jilba.txt","rt");
	while (!feof(Jilba))
	{
		fgets(string_from_a_file, 100, Jilba);
		if (strstr(string_from_a_file, operator_if) != NULL)
		{
			pointer_in_a_string = strstr(string_from_a_file, operator_if);
			if ((string_from_a_file[0] == 'i') && (string_from_a_file[1] == 'f') && (string_from_a_file[2] == ' '))
			{
				number_of_operator_if++;
			}
			else
			{
				if (((string_from_a_file[pointer_in_a_string - string_from_a_file - 1]) == ' ') && ((string_from_a_file[pointer_in_a_string - string_from_a_file + 2]) == ' '))
				{ 
					number_of_operator_if++;
				}
			}
		}

		for (i = 0; i < N; i++)
		{
			if (strstr(string_from_a_file, operators[i].current_string) != NULL)
			{
				pointer_in_a_string = strstr(string_from_a_file, operators[i].current_string);
				if (((string_from_a_file[pointer_in_a_string - string_from_a_file + strlen(operators[i].current_string)]) == ' ') || ((string_from_a_file[pointer_in_a_string - string_from_a_file - 1]) == ' ') || (((string_from_a_file[pointer_in_a_string - string_from_a_file + strlen(operators[i].current_string)]) == ';')) || (((string_from_a_file[pointer_in_a_string - string_from_a_file + strlen(operators[i].current_string)]) == '.')) || ((string_from_a_file[pointer_in_a_string - string_from_a_file + strlen(operators[i].current_string)]) == '\n'))
				{
					total_number_of_operators++;
				}
			}
		}
	}
	total_number_of_operators = total_number_of_operators + number_of_operator_if;
	i = 0;
	fclose(Jilba);
	
	Jilba = fopen("Jilba.txt","rt");
	while (!feof(Jilba))
	{	
		fgets(string_from_a_file, 100, Jilba);
		fscanf(Jilba, "%s", &string_from_a_file);
		if (strcmp(string_from_a_file, operator_if) == 0)
		{
			maximum_level_of_nesting++;
		}
		if ((strcmp(string_from_a_file, operator_end)) == 0)
		{
			massive[i] = maximum_level_of_nesting;
			i++;
			maximum_level_of_nesting = 0;
		}
	}
	fclose(Jilba);

	for (i = 0; i < 10; i++)
	{
		if (massive[i] < 0)
		{
			massive[i] = 0;
		}
		maximum_level_of_nesting = massive[i];
	}


	for (i = 0; i < 10; i++)
	{
		if (maximum_level_of_nesting < massive[i])
		{
			maximum_level_of_nesting = massive[i];
		}
	}

	result = float(number_of_operator_if) / (total_number_of_operators);

    printf("Абсолютная сложность программы(CL): %d\n", number_of_operator_if);
    printf("Общее количетсво операторов(N): %d\n", total_number_of_operators);
    printf("Относительная сложность программы(cl=CL/N): %f\n", result);
	printf("Максимальный уровень вложенности(CLI): %d", maximum_level_of_nesting);
   
    getchar();
    return 0;
}