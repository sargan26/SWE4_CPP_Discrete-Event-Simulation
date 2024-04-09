# **SWE4-Übungen - SS2024 - Übungszettel 2 - Ausarbeitung**

## **Beispiel 1**

### **Lösungsidee**

#### Einleitung

Dieser Abschnitt beschreibt die Kernaspekte der entwickelten Simulationsbibliothek zur Abbildung diskreter Ereignisse innerhalb 
einer modellierten Umgebung. 
Die Bibliothek findet Anwendung in der Simulation einer Straßenkreuzung sowie in einem Eisladen-Szenario, wobei Letzteres als 
Beispiel zur Demonstration dient, dass die Klasse allgemein eingesetzt werden kann.

#### Kernkomponenten

Die Simulationsbibliothek basiert auf folgenden Hauptkomponenten:

- `Event`: Abstrakte Basisklasse, von der alle Ereignistypen abgeleitet werden. Jedes Ereignis besitzt einen Zeitstempel (`time`), zu dem es verarbeitet werden soll.

- `Simulation`: Kernklasse, die eine Priority Queue (`eventQueue`) verwaltet, um Ereignisse basierend auf ihren Zeitstempeln zu ordnen und auszuführen. Die Klasse bietet Methoden wie `run()` zum Ausführen der Simulation und `scheduleEvent()` zum Einplanen neuer Ereignisse.

- `StoreSimulation`: Spezialisierte Simulation, die ein Szenario eines Eisladens modelliert. Diese Klasse erweitert `Simulation` um geschäftsspezifische Logik wie Sitzplatzverwaltung und Gewinnberechnung.

- `Event-Klassen`: Spezifische Ereignisse wie `ArriveEvent`, `OrderEvent`, `LeaveEvent` für die Eisladen-Simulation. Jede Klasse implementiert `processEvent()`, um die Logik des Ereignisses zu definieren.

#### Funktionsweise der Algorithmen

- **Ereignisverarbeitung**: Die Simulation arbeitet Ereignisse in der Reihenfolge ihrer Zeitstempel ab. Bei Ausführung wird `processEvent()` jedes Ereignisses aufgerufen, wodurch die spezifische Logik des Ereignisses ausgeführt und der Zustand der Simulation geändert wird.

- **Ereignisplanung**: Neue Ereignisse werden mittels `scheduleEvent()` erzeugt und der `eventQueue` hinzugefügt. Die Priority Queue stellt sicher, dass Ereignisse chronologisch abgearbeitet werden.

#### Grundstruktur der Implementierung

- Die Beziehung zwischen `Simulation` und Ereignisklassen demonstriert die Anwendung des Observer-Musters, wobei `Simulation` Ereignisse beobachtet und bei Eintreten verarbeitet.

- `storeSimulation` agiert als konkrete Implementierung der abstrakten `Simulation`, wodurch die Anwendbarkeit der Bibliothek auf verschiedene Szenarien verdeutlicht wird.

- Die Verwendung von `std::unique_ptr` für Ereignisse innerhalb der Priority Queue unterstreicht das Prinzip des modernen C++-Managements von Ressourcen.

### **Testfälle**

## **Beispiel 2**

### **Lösungsidee**

# Lösungsidee für die Straßenkreuzungssimulation

#### Einleitung

Die Simulation einer Straßenkreuzung demonstriert die Anwendung der entwickelten Simulationsbibliothek. Diese Simulation modelliert das Verkehrsverhalten an einer Kreuzung, die von zwei Straßen gebildet wird, mit Ampelregelung für jede Fahrtrichtung. Im Fokus stehen die Dynamiken der Fahrzeugankünfte, die Ampelphasen und die Verarbeitung der Wartezeiten.

#### Kernkomponenten und Funktionsweise

##### Klassenstruktur

- `TrafficSimulation`: Koordiniert die Simulation und verwaltet vier `Lane`-Instanzen, die jeweils eine Fahrtrichtung repräsentieren.

- `Lane`: Erbt von der `simulation`-Klasse und repräsentiert eine Fahrtrichtung an der Kreuzung. Jede Lane verwaltet ihre eigene Ampel und die zugehörigen Fahrzeugereignisse.

- `Car`: Modelliert ein einzelnes Fahrzeug mit eindeutiger ID und Modellbezeichnung.

- Ereignisklassen (`ArriveCarEvent`, `LeaveCarEvent`, `TrafficLightSwitchEvent`, `PrintStatisticsEvent`, `ExportStatisticsEvent`): Spezifische Ereignistypen, die die Logik der Ankunft und Abfahrt von Fahrzeugen, Ampelumschaltungen und Statistikexport implementieren.

##### Funktionsweise

- **Ampelsteuerung**: Die Simulation startet mit Grünphasen für die Nord-Süd-Richtung und Rotphasen für Ost-West. Die Ampelphasen wechseln regelmäßig durch `TrafficLightSwitchEvent`.

- **Fahrzeugankünfte**: Fahrzeuge erreichen die Kreuzung in jeder Fahrtrichtung zu zufälligen Zeitpunkten, basierend auf einer Exponentialverteilung. `ArriveCarEvent`-Instanzen werden generiert und geplant.

- **Fahrzeugabfahrten**: Wenn ein Fahrzeug an einer grünen Ampel ankommt und keine Warteschlange vorhanden ist, verlässt es die Kreuzung sofort. Andernfalls reiht es sich in die Warteschlange ein und wartet auf ein `LeaveCarEvent`, dessen Zeitpunkt normalverteilt ist.

- **Statistikerfassung und -export**: `PrintStatisticsEvent` und `ExportStatisticsEvent` werden genutzt, um regelmäßig Statistiken zu Mindest-, Maximal- und Durchschnittswartezeiten sowie zur Länge der Warteschlange zu erfassen und zu exportieren.

#### Implementierungsdetails

- Die Implementierung nutzt `std::unique_ptr` für Ereignisobjekte und eine Priority Queue innerhalb jeder `Lane` für die Ereignisverarbeitung.

- Die Ereignisverarbeitung (`processEvent`) in den Ereignisklassen manipuliert die Zustände der `Lane`, wie das Umschalten der Ampel und das Zählen von Fahrzeugen.

- Statistiken werden in CSV-Dateien exportiert, wobei für jede `Lane` eine separate Datei generiert wird, um die Analysierbarkeit zu erleichtern.

### **Testfälle**
