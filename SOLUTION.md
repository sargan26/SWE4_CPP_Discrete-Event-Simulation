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

### **Testfälle**
