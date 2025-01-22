#include <stdio.h>
#include <string.h>
#include <time.h> /* used to specify the current month (or time) */

int main( ) {
  FILE *file;
  char line[256];
  char month_str[20];
  time_t t = time( NULL );
  struct tm tm = *localtime( &t );

  // Bestimme den aktuellen Monat als String. Hier wird das Format [january] verwendet.
  switch( tm.tm_mon ) {
  case 0:
    strcpy( month_str, "[january]" );
    break;
  case 1:
    strcpy( month_str, "[february]" );
    break;
  // ... für die anderen Monate analog ...
  case 11:
    strcpy( month_str, "[december]" );
    break;
  default:
    strcpy( month_str, "" );
    break; // Fallback
  }

  file =
    fopen( "deine_datei.txt", "r" ); // Ersetze "deine_datei.txt" durch den tatsächlichen Dateinamen
  if( file == NULL ) {
    perror( "Fehler beim Öffnen der Datei" );
    return 1;
  }

  int print_lines = 0;
  while( fgets( line, sizeof( line ), file ) != NULL ) {
    if( strstr( line, month_str ) != NULL ) {
      print_lines = 1; // Beginne mit dem Drucken der Zeilen
    } else if( print_lines && line[0] == '[' ) {
      break; // Beende das Drucken, wenn eine neue Monatsmarke gefunden wird
    }

    if( print_lines ) {
      printf( "%s", line );
    }
  }

  fclose( file );
  return 0;
}

/* explanation to the code above in german */
/* Aktuellen Monat feststellen: Du kannst die time.h-Bibliothek verwenden, um den aktuellen Monat zu
 * bestimmen. */
/* Datei zeilenweise lesen: Du liest die Datei zeilenweise und prüfst, ob die Zeile den aktuellen
 * Monat enthält. */
/* Monat bestimmen: time.h wird verwendet, um die aktuelle Zeit zu bekommen.  */
/* localtime konvertiert diese Zeit in ein struct tm, das den Monat als tm_mon (0-11) enthält.  */
/* Ein switch-Statement konvertiert diesen Wert in den entsprechenden Monatsstring. */
/* Datei lesen: Die Datei wird geöffnet und fgets wird verwendet, um Zeilen zu lesen.  */
/* Wenn eine Zeile gefunden wird, die den aktuellen Monat enthält, setzt print_lines auf 1  */
/* und alle nachfolgenden Zeilen werden gedruckt, bis eine neue Monatsmarke (eine Zeile, die mit '['
 * beginnt) gefunden wird. */
/* Datei schließen: Nach dem Lesen wird die Datei geschlossen. */
/* Beachte, dass der Dateiname und die Monatsnamen in den Klammern genau so in der Datei */
/* stehen müssen, wie sie im Code definiert sind. */
/* Auch sollten die Monate in der Datei in der korrekten Reihenfolge aufgelistet sein. */

// same code but with more comments

#include <stdio.h>
#include <string.h>
#include <time.h>

int main( ) {
  // Dateizeiger für die Eingabedatei
  FILE *file;
  // Puffer für Zeilen, die aus der Datei gelesen werden
  char line[256];
  // String, der den aktuellen Monat enthält
  char month_str[20];
  // Aktuelle Zeit holen
  time_t t = time( NULL );
  // Zeit in lokalzeit umwandeln
  struct tm tm = *localtime( &t );

  // Bestimme den aktuellen Monat als String. Hier wird das Format [january] verwendet.
  switch( tm.tm_mon ) {
  case 0:
    strcpy( month_str, "[january]" );
    break;
  case 1:
    strcpy( month_str, "[february]" );
    break;
  // ... für die anderen Monate analog ...
  case 11:
    strcpy( month_str, "[december]" );
    break;
  default:
    strcpy( month_str, "" );
    break; // Fallback für ungültige Werte
  }

  // Öffne die Datei im Lesemodus
  file =
    fopen( "deine_datei.txt", "r" ); // Ersetze "deine_datei.txt" durch den tatsächlichen Dateinamen
  if( file == NULL ) {
    // Fehlerbehandlung, falls Datei nicht geöffnet werden kann
    perror( "Fehler beim Öffnen der Datei" );
    return 1;
  }

  // Flag, das anzeigt, ob Zeilen gedruckt werden sollen
  int print_lines = 0;
  while( fgets( line, sizeof( line ), file ) != NULL ) {
    // Prüfe, ob die aktuelle Zeile den gesuchten Monat enthält
    if( strstr( line, month_str ) != NULL ) {
      print_lines = 1; // Beginne mit dem Drucken der Zeilen
    } else if( print_lines && line[0] == '[' ) {
      // Wenn eine neue Monatsmarke gefunden wird, beenden wir das Drucken
      break;
    }

    // Wenn wir in der Druckphase sind, drucken wir die Zeile
    if( print_lines ) {
      printf( "%s", line );
    }
  }

  // Datei schließen, um Ressourcen freizugeben
  fclose( file );
  return 0;
}

/* explanation tho the code above in german */
/* Zeilenpuffer und Dateizeiger: Erklärung, warum diese Variablen notwendig sind. */
/* Zeit und Datum: Kurze Erklärung der Zeitumwandlung. */
/* Monatsbestimmung: Erläuterung des switch-Statements zur Konvertierung des Monats in Stringform.
 */
/* Datei öffnen: Fehlerbehandlung beim Öffnen der Datei. */
/* Leseschleife: Detaillerete Beschreibung der Bedingungen, wann und wie Zeilen gedruckt werden. */
/* Datei schließen: Wichtigkeit der Ressourcenfreigabe. */

// same code but with more error handling

#include <stdio.h>
#include <stdlib.h> // Für exit() Funktion
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 256
#define MAX_MONTH_LENGTH 20

int main( ) {
  FILE *file = NULL;
  char line[MAX_LINE_LENGTH];
  char month_str[MAX_MONTH_LENGTH];
  time_t t;
  struct tm *tm;

  // Aktuelle Zeit holen
  t = time( NULL );
  if( t == ( time_t ) -1 ) {
    fprintf( stderr, "Fehler beim Abrufen der aktuellen Zeit.\n" );
    exit( EXIT_FAILURE );
  }

  // Zeit in lokalzeit umwandeln
  tm = localtime( &t );
  if( tm == NULL ) {
    fprintf( stderr, "Fehler bei der Konvertierung der Zeit.\n" );
    exit( EXIT_FAILURE );
  }

  // Bestimme den aktuellen Monat als String. Hier wird das Format [january] verwendet.
  switch( tm->tm_mon ) {
  case 0:
    strcpy( month_str, "[january]" );
    break;
  case 1:
    strcpy( month_str, "[february]" );
    break;
  // ... für die anderen Monate analog ...
  case 11:
    strcpy( month_str, "[december]" );
    break;
  default:
    fprintf( stderr, "Ungültiger Monatswert erhalten.\n" );
    exit( EXIT_FAILURE );
  }

  // Öffne die Datei im Lesemodus
  file =
    fopen( "deine_datei.txt", "r" ); // Ersetze "deine_datei.txt" durch den tatsächlichen Dateinamen
  if( file == NULL ) {
    perror( "Fehler beim Öffnen der Datei" );
    exit( EXIT_FAILURE );
  }

  // Flag, das anzeigt, ob Zeilen gedruckt werden sollen
  int print_lines = 0;
  while( fgets( line, MAX_LINE_LENGTH, file ) != NULL ) {
    // Fehlerbehandlung für fgets
    if( ferror( file ) ) {
      fprintf( stderr, "Fehler beim Lesen der Datei.\n" );
      fclose( file );
      exit( EXIT_FAILURE );
    }

    // Prüfe, ob die aktuelle Zeile den gesuchten Monat enthält
    if( strstr( line, month_str ) != NULL ) {
      print_lines = 1; // Beginne mit dem Drucken der Zeilen
    } else if( print_lines && line[0] == '[' ) {
      // Wenn eine neue Monatsmarke gefunden wird, beenden wir das Drucken
      break;
    }

    // Wenn wir in der Druckphase sind, drucken wir die Zeile
    if( print_lines ) {
      printf( "%s", line );
    }
  }

  // Fehlerbehandlung nach dem Lesen der Datei
  if( ferror( file ) ) {
    fprintf( stderr, "Fehler beim Lesen der Datei.\n" );
    fclose( file );
    exit( EXIT_FAILURE );
  }

  // Datei schließen, um Ressourcen freizugeben
  if( fclose( file ) != 0 ) {
    perror( "Fehler beim Schließen der Datei" );
    exit( EXIT_FAILURE );
  }

  return 0;
}

/* explanation to the above code in german */
/* Zeitabruf und -konvertierung: Prüfung, ob time und localtime erfolgreich waren, bevor weitere
 * Operationen durchgeführt werden. */
/* Monatsbestimmung: Ein default-Fall im switch für fehlerhafte Monatswerte. */
/* Datei öffnen und lesen: Zusätzliche Fehlerprüfungen nach jedem fgets-Aufruf und bei der
 * Dateischließung. */
/* Fehlerbehandlung mit exit(): Bei schwerwiegenden Fehlern wird das Programm mit exit(EXIT_FAILURE)
 * beendet, was eine klare Indikation für den Benutzer ist, dass etwas schief gelaufen ist. */

// same code but with more details to the issues

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 256
#define MAX_MONTH_LENGTH 20

// Funktion zum Drucken von spezifischen Fehlermeldungen
void print_error( const char *msg ) {
  fprintf( stderr, "Fehler: %s (%s)\n", msg, strerror( errno ) );
  exit( EXIT_FAILURE );
}

int main( ) {
  FILE *file = NULL;
  char line[MAX_LINE_LENGTH];
  char month_str[MAX_MONTH_LENGTH];
  time_t t;
  struct tm *tm;

  // Aktuelle Zeit holen
  t = time( NULL );
  if( t == ( time_t ) -1 ) {
    print_error( "Konnte aktuelle Zeit nicht abrufen" );
  }

  // Zeit in lokalzeit umwandeln
  tm = localtime( &t );
  if( tm == NULL ) {
    print_error( "Fehler beim Konvertieren der Zeit" );
  }

  // Bestimme den aktuellen Monat als String. Hier wird das Format [january] verwendet.
  switch( tm->tm_mon ) {
  case 0:
    strcpy( month_str, "[january]" );
    break;
  case 1:
    strcpy( month_str, "[february]" );
    break;
  // ... für die anderen Monate analog ...
  case 11:
    strcpy( month_str, "[december]" );
    break;
  default:
    print_error( "Ungültiger Monatswert erhalten" );
  }

  // Öffne die Datei im Lesemodus
  file =
    fopen( "deine_datei.txt", "r" ); // Ersetze "deine_datei.txt" durch den tatsächlichen Dateinamen
  if( file == NULL ) {
    print_error( "Konnte Datei nicht öffnen" );
  }

  // Flag, das anzeigt, ob Zeilen gedruckt werden sollen
  int print_lines = 0;
  while( fgets( line, MAX_LINE_LENGTH, file ) != NULL ) {
    // Fehlerbehandlung für fgets
    if( ferror( file ) ) {
      print_error( "Fehler beim Lesen der Datei" );
    }

    // Prüfe, ob die aktuelle Zeile den gesuchten Monat enthält
    if( strstr( line, month_str ) != NULL ) {
      print_lines = 1; // Beginne mit dem Drucken der Zeilen
    } else if( print_lines && line[0] == '[' ) {
      // Wenn eine neue Monatsmarke gefunden wird, beenden wir das Drucken
      break;
    }

    // Wenn wir in der Druckphase sind, drucken wir die Zeile
    if( print_lines ) {
      printf( "%s", line );
    }
  }

  // Fehlerbehandlung nach dem Lesen der Datei
  if( ferror( file ) ) {
    print_error( "Fehler beim Lesen der Datei" );
  }

  // Datei schließen, um Ressourcen freizugeben
  if( fclose( file ) != 0 ) {
    print_error( "Fehler beim Schließen der Datei" );
  }

  return 0;
}

/* explanation to the code above in german */
/* Fehlermeldungsfunktion: print_error gibt eine spezifische Fehlerbeschreibung
 * zusammen mit dem vom System bereitgestellten Fehlermeldungstext (strerror(errno)) aus.
 * Dies hilft, den genauen Grund des Fehlers zu identifizieren. */
/* Zeitabruf und -konvertierung: Zusätzliche Fehlerprüfungen, um sicherzustellen, dass die
 * Zeitkorrekt ermittelt wird. */
/* Monatsbestimmung: Ein default-Fall im switch für unerwartete Monatswerte. */
/* Dateioperationen: Fehlerprüfungen bei jedem Schritt des Dateihandlings, von Öffnen über Lesen bis
 * Schließen. */
/* Fehlerbehandlung: Jeder Fehler führt zu einem sofortigen Programmabbruch (exit(EXIT_FAILURE)),
 * was besonders nützlich ist, um Ressourcenlecks zu vermeiden und dem Benutzer eine klare
 * Rückmeldung zu geben. */

// same code but with even more comments

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 256
#define MAX_MONTH_LENGTH 20

// Funktion zum Drucken von spezifischen Fehlermeldungen
void print_error( const char *msg ) {
  // Gibt die Fehlermeldung und den entsprechenden Systemfehlertext aus
  fprintf( stderr, "Fehler: %s (%s)\n", msg, strerror( errno ) );
  // Beendet das Programm mit einem Fehlersignal
  exit( EXIT_FAILURE );
}

int main( ) {
  FILE *file = NULL;
  char line[MAX_LINE_LENGTH];
  char month_str[MAX_MONTH_LENGTH];
  time_t t;
  struct tm *tm;

  // Versuche, die aktuelle Zeit zu holen
  t = time( NULL );
  if( t == ( time_t ) -1 ) {
    // Überprüfe, ob time() fehlgeschlagen ist
    print_error( "Konnte aktuelle Zeit nicht abrufen. Dies könnte durch einen Systemfehler oder "
                 "Zeitgrenzenprobleme verursacht sein." );
  }

  // Konvertiere die Zeit in lokale Zeit
  tm = localtime( &t );
  if( tm == NULL ) {
    // Überprüfe, ob localtime() fehlgeschlagen ist
    print_error( "Fehler beim Konvertieren der Zeit. Möglicherweise liegt ein Problem mit der "
                 "Zeitbibliothek oder dem System vor." );
  }

  // Bestimme den aktuellen Monat als String. Hier wird das Format [january] verwendet.
  switch( tm->tm_mon ) {
  case 0:
    strcpy( month_str, "[january]" );
    break;
  case 1:
    strcpy( month_str, "[february]" );
    break;
  // ... für die anderen Monate analog ...
  case 11:
    strcpy( month_str, "[december]" );
    break;
  default:
    // Überprüfe auf unerwartete Monatswerte
    print_error( "Ungültiger Monatswert erhalten. Das System hat einen Monat geliefert, der "
                 "außerhalb des erwarteten Bereichs liegt." );
  }

  // Öffne die Datei im Lesemodus
  file =
    fopen( "deine_datei.txt", "r" ); // Ersetze "deine_datei.txt" durch den tatsächlichen Dateinamen
  if( file == NULL ) {
    // Überprüfe, ob die Datei nicht geöffnet werden konnte
    print_error( "Konnte Datei nicht öffnen. Möglicherweise existiert die Datei nicht, oder es "
                 "sind keine Zugriffsrechte vorhanden." );
  }

  // Flag, das anzeigt, ob Zeilen gedruckt werden sollen
  int print_lines = 0;
  while( fgets( line, MAX_LINE_LENGTH, file ) != NULL ) {
    // Überprüfe auf Lese-Fehler während des Lesens der Datei
    if( ferror( file ) ) {
      print_error( "Fehler beim Lesen der Datei. Dies könnte auf ein Problem mit der Festplatte "
                   "oder der Dateiberechtigung hinweisen." );
    }

    // Prüfe, ob die aktuelle Zeile den gesuchten Monat enthält
    if( strstr( line, month_str ) != NULL ) {
      print_lines = 1; // Beginne mit dem Drucken der Zeilen
    } else if( print_lines && line[0] == '[' ) {
      // Wenn eine neue Monatsmarke gefunden wird, beenden wir das Drucken
      break;
    }

    // Wenn wir in der Druckphase sind, drucken wir die Zeile
    if( print_lines ) {
      printf( "%s", line );
    }
  }

  // Überprüfe auf Lese-Fehler nach dem Schleifenende
  if( ferror( file ) ) {
    print_error( "Fehler beim Lesen der Datei. Möglicherweise wurde die Datei während des Lesens "
                 "beschädigt oder gelöscht." );
  }

  // Datei schließen, um Ressourcen freizugeben
  if( fclose( file ) != 0 ) {
    // Überprüfe, ob das Schließen der Datei fehlgeschlagen ist
    print_error( "Fehler beim Schließen der Datei. Dies kann zu einem Ressourcenleck führen." );
  }

  return 0;
}

/* explanation to the above code in german */
/* Zeitabruf und -konvertierung: Es wird erklärt, was die Ursachen für Fehler bei diesen Operationen
 * sein könnten. */
/* Monatsbestimmung: Hinweise darauf, was ein ungültiger Monatswert bedeuten könnte. */
/* Dateioperationen: Ausführliche Erklärungen zu möglichen Gründen für Fehler beim Öffnen, Lesen und
 * Schließen der Datei. */
/* Fehlerbehandlung: Jeder Fehler wird klar beschrieben, was dem Benutzer hilft, das Problem besser
 * zu verstehen und zu diagnostizieren. */
