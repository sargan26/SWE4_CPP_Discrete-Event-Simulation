[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/04cFE6bA)
# **SWE4-Übungen - SS2024 - Übungszettel 2**

## Discrete Event Simulation (src/des)

Implementieren Sie ein C++-Programm, das diskrete Prozesse simulieren kann. Ein
Prozess ist diskret, wenn sich nur zu endlichen vielen Zeitpunkten der
Systemzustand ändern kann. Als Methode soll die diskrete Ereignissimulation
eingesetzt werden. Bei dieser Methode wird nicht in Realzeit simuliert, sondern
es werden nur jene Zeitpunkte betrachtet, zu denen Änderungen am System
eintreten. Die Zeit zwischen diesen Ereignissen kann vernachlässigt werden. Das
kann die benötigte Simulationszeit drastisch reduzieren, da nur interessante
Zeitpunkte betrachtet werden. Herzstück eines solchen Simulators ist daher eine
Liste mit noch ausstehenden Ereignissen, die in der Zukunft passieren werden.
Diese Liste muss nach der Zeit aufsteigend sein. Es ist aber ausreichend, wenn
sie die Ermittlung des nächsten Ereignisses effizient unterstützt. Da jederzeit
neue Ereignisse hinzukommen können und die Anzahl der Ereignisse mitunter sehr
beachtlich ausfallen kann, ist die Wahl einer geeigneten Datenstruktur
essenziell. Hier bietet sich die C++Standardbibliothek mit ihrer großen Anzahl
an sehr effizient implementierten Datenstrukturen an. 

1. Recherchieren Sie mögliche Designansätze und passende Datenstrukturen für
   diese Aufgabenstellung und implementieren Sie eine möglichst allgemein
   einsetzbare Simulationsbibliothek in Form von C++-Klassen. Folgende
   Funktionalität muss mindestens verfügbar sein:

   * Zukünftige Ereignisse müssen für einen bestimmten Zeitpunkt geplant werden
     können und in einer effizienten Datenstruktur gehalten werden.
   * Ereignisse müssen andere Ereignisse (in derselben Simulation) erzeugen
     können. Überlegen Sie hier, welche API Sie verwenden, um diesen Aspekt, der
     in der Praxis häufig gebraucht wird, möglichst komfortabel gestalten zu
     können. 
   * Das System muss verschiedene Arten von Ereignissen unterstützen. Es soll
     einfach möglich sein, neue Ereignistypen hinzuzufügen. 
   * Die Simulation muss schrittweise ausgeführt werden können. Es muss also z.
     B. eine Methode `step()` geben die einfach nur das nächste Ereignis
     abarbeitet. 
   * Die Simulation muss bis zu einem bestimmten Kriterium ausgeführt werden
     können, nachdem sie entweder pausiert oder stoppt. Es muss also z.B. eine
     Methode `run()` geben, die durch Ereignisse in der Simulation beendet
     werden kann.

2. Demonstrieren Sie die korrekte Funktionsweise Ihrer Bibliothek anhand der
   Simulation einer Straßenkreuzung. Folgendes Szenario soll auf Ihr
   Simulationsmodell abgebildet werden:
   * An der zu simulierenden Kreuzung überschneiden sich zwei Straßen.
   * Die Kreuzung ist ampelgeregelt. Ist die Ampel für eine Straße auf grün
     geschaltet, zeigt die Ampel für die andere Straße rot. Es gibt keine
     Zusatzampeln zum Rechts- oder Linksabbiegen u. dgl.
   * Die Kreuzung ist mit Verkehrssensoren ausgestattet. Diese werden verwendet,
     um die Grünphase zu verlängern, wenn die Warteschlange auf einer der beiden
     Straßen länger ist als auf der anderen. 
   * Trifft ein Fahrzeug in einer Grünphase auf die Kreuzung, überquert es die
     Kreuzung ohne Zeitverzögerung. Bei rot bzw. wenn sich bereits Fahrzeuge in
     der Warteschlange befinden, reiht es es sich hinten in die Warteschlange
     ein.
   * Stehende Fahrzeuge (solche, die sich in der Warteschlange befinden)
     benötigen eine gewisse Zeit zum Ausfahren aus der Kreuzung (die
     Ausfahrtszeit ist normalverteilt). Das nachfolgende Fahrzeug startet erst,
     wenn das davor befindliche die Kreuzung vollständig verlassen hat.
   * Die Anzahl der ankommenden Fahrzeuge ist für die vier Fahrrichtungen
     unterschiedlich und ändert sich im Laufe eines Tages. Die
     Zwischenankunftszeit von Fahrzeugen ist exponentialverteilt. 
     
   Simulieren Sie das Verkehrsaufkommen bei dieser Kreuzung für einen Tag und
   ermitteln Sie für die Länge der Wartschlange und die Wartezeit an der Ampel
   jeweils den minimalen, maximalen und durchschnittlichen Wert. Bestimmen Sie
   diese Kennzahlen für jede der vier Fahrrichtungen. Vergleichen Sie die
   Ergebnisse bei ein- und ausgeschalteten Verkehrssensoren (Länge der
   Grün/Rot-Phasen hängt vom Verkehrsaufkommen ab).

3. Ermitteln Sie in regelmäßigen Abständen die durchschnittliche Länge der
   Warteschlange und die durchschnittliche Wartezeit für einen bestimmen
   Zeitbereich (Verwenden Sie dafür am besten einen eigenen Event-Typ).
   Exportieren Sie diese Werte in eine CSV-Datei und stellen Sie diese graphisch
   (z. B. in Excel) dar. Stellen Sie auch hier dar, welchen Einfluss die
   Verkehrssensoren auf das Ergebnis haben. 
   
### Technologische Anforderungen: 
* Achten Sie auf ein sauberes objektorientiertes Design. 
* Verwenden Sie möglichst viele Klassen und Konzepte der C++-BehälterBibliothek
  (Behälterklassen, Algorithmen, Funktionsobjekte). Setzen Sie zur Realisierung
  der Ereigniswarteschlange die Datenstruktur `std::priority_queue<>` ein.
  Verwenden Sie die Zufallszahlengeneratoren der C++Standardbibliothek. Diese
  bietet auch Möglichkeiten, Zufallszahlen, die eine bestimmte Verteilung
  aufweisen, zu generieren.
* Achten Sie darauf, dass Ihr System mit neuen Event-Typen einfach erweiterbar
  ist. Das können Sie am einfachsten gewährleisten, indem Sie eine abstrakte
  Basisklasse für Events anbieten, von der konkrete Event-Typen abgeleitet
  werden können.
* Verwenden Sie zur Verwaltung von dynamisch erzeugten Objekten konsequent
  Smart-Pointer-Klassen aus der STL. Es sollte an keiner Stelle in Ihrem
  Programm notwendig sein, die Schlüsselwörter `new` oder `delete` einzusetzen. 
* Vermeiden Sie globale Variablen.