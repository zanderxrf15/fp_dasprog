#include <stdio.h>
#include <string.h>

int T;
int temp = 0;
char commands[100];
char icon[100];
char x[100];
char y[100];

typedef struct
{
  int bombs;
  char track1[100];
  char army[100];
  char track2[100];
} military;

int PlantingBombs (military * dossier, char *check, int temp)
{
  for (int i = 0; i < T; i++)
    {
      int P = dossier[i].bombs;
      if (!strcmp (check, dossier[i].army))
	{
	  return PlantingBombs (dossier, dossier[i].track2, temp);
	}
      else if (!strcmp (check, dossier[i].track1) && temp == 0)
	{
	  return P;
	}
      else if (!strcmp (check, dossier[i].track1))
	{
	  dossier[i].bombs = temp;
	return P;
	}
    }
  return -1;
}

int
main ()
{
  scanf ("%i", &T);
  military database[T];
  for (int i = 0; i < T; i++)
    {
      scanf ("%s", commands);
      if (!strcmp (commands, "set"))
	{
	  scanf ("%s", icon);
	}
      if (!strcmp (commands, "set") && !strcmp (icon, "*"))
	{
	  scanf ("%s & ", database[i].army);
	  scanf ("%s", database[i].track2);
	}
      else
	{
	  strcpy (database[i].track1, icon);
	  scanf ("%d", &database[i].bombs);
	}
      if (!strcmp (commands, "get"))
	{
	  scanf (" * %s", icon);
	  printf ("%d\n", PlantingBombs (database, icon, temp));
	}
      if (!strcmp (commands, "chg"))
	{
	  scanf ("%s", icon);
	  if (!strcmp (icon, "*"))
	    {
	      scanf ("%s", x);
	      for (int i = 0; i < T; i++)
		{
		  if (!strcmp (x, database[i].army))
		    {
		      scanf ("&");
		      scanf ("%s", y);
		      if (!strcmp (y, "&"))
			{
			  scanf ("%s", database[i].track2);
			}
		      else
			{
			  PlantingBombs (database, database[i].track2, atoi (y));
			}
		    }
		}
	    }
	  else
	    {
	      for (int i = 0; i < T; i++)
		{
		  if (!strcmp (icon, database[i].army))
		    {
		      scanf ("%s", database[i].track2);
		    }
		  else if (!strcmp (icon, database[i].track1))
		    {
		      scanf ("%d", &database[i].bombs);
		    }
		}
	    }
	}
    }
}
