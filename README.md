Aufgabe
Es soll die Verwaltungssoftware für eine Autovermietung implementiert werden. Die Autovermietung besitzt mehrere unterschiedliche Fahrzeuge. Die Fahrzeuge unterscheiden sich in der Anzahl an Passagiere, die sie neben dem Fahrer transportieren können, und was für eine Führerscheinklasse der Fahrer besitzen muss.


Wenn jemand ein Auto mieten will, dann gibt er/sie die Führerscheinklasse und die Anzahl der Passagiere an. Daraufhin wählt die Verwaltungssoftware ein passendes Auto aus. Dabei soll die Anzahl der leer bleibenden Plätze möglichst minimiert werden, d.h. die Verwaltungssoftware soll das Auto auswählen, bei dem die wenigsten Passagierplätze frei bleiben.


Führerscheinklassen werden durch Nummern von 1 - 5 repräsentiert, dabei repräsentiert die 1 die niedrigste Führerscheinklasse und 5 die höchste. Die Führerscheinklassen sind hierarchisch, d.h. wenn jemand die Führerscheinklasse 4 besitzt, kann er/sie Autos fahren, die Führerscheinklasse 1 -- 4 vorraussetzen, aber nicht Autos mit Führerscheinklasse 5.


Bei jedem Mietvorgang wird auch die Fahrtüchtigkeit der Autos überprüft und bei entdeckten Schäden soll eine Exception geworfen werden. Bei einem kaputten Motor (BrokenMotorException) bzw. einer kaputten Elektronik (ElectronicsFaultException) muss das Auto ausgemustert werden, d.h. es wird aus der Verwaltungssoftware gelöscht und verschrottet. Bei zu hohen Abgaswerten (EmissionsTooDirtyException) wird angenommen, dass das nur vorübergehend ist, d.h. es wird nicht aus der Verwaltungssoftware gelöscht und die Fahrtüchtigkeit beim nächsten Verleihvorgang nochmals überprüft.


In der main()-Funktion fügen Sie mehrere Autos zur Autovermietung hinzu und führen die simulate()-Objektfunktion der Autovermietung aus.

Implementieren Sie entsprechende Ausgaben am Bildschirm, damit man auch genau nachverfolgen kann, was in Ihrem Programm passiert.


Grundlegende Softwarearchitektur
Die grundlegende Software-Architektur schaut folgendermaßen aus:


Public Interface
Das im folgenden gegebene öffentliche Interface soll genauso wie angegebene implementiert werden. Sie können dieses auch um weitere Funktionen erweitern, wenn Sie dies für nötig erachten.

Klasse CarRental
Die Klasse CarRental repräsentiert die Autovermietung selber und implementiert die zentrale Verwaltungsfunktionen. Da ständig neue Autos aufgenommen und alte ausgeschieden werden, wird für deren Verwaltung ein dynamischer Datencontainer benötigt. Bestimmen Sie selbstständig einen passenden Datencontainer. Autos werden durch eindeutige nummerische IDs identifiziert.
	• Objektfunktionen:
		○ int addCar(Car* car): Fügt ein neues Auto hinzu. Der Rückgabewert ist eine eindeutige ID, die das Auto identifiziert.
		○ Car* getCar(int id): Gibt das Auto mit der angegebenen ID zurück.
		○ void deleteCar(int id): Entfernt das Auto mit der angegebenen ID und gibt alle damit verbundenen Ressourcen wieder frei.
		○ Car* rentCar(int licenceType, int passengerCount): Gibt ein passendes fahrtüchtiges Auto zurück, dass mit der angegeben Führerscheinklasse gefahren werden darf und mindestens die angegebene Anzahl an Passagieren befördern kann. Dabei sollen die frei bleibenden Passagierplätze minimal sein. Das Auto darf auch nicht schon an andere vermietet und muss fahrtüchtig sein. Die Fahrtüchtigkeit wird mit 
		der checkCar()-Objektfunktion überprüft. Falls kein passendes Fahrzeug gefunden werden konnte, soll eine NoCarFoundException geworfen werden.


		○ void simulate(int rentals): Simuliert die angegebene Anzahl an Mietvorgängen. Die Führerscheinklasse und die Anzahl an Passagieren soll dabei bei jedem Mietvorgang zufällig bestimmt werden.
		
Klasse Car
Die Klasse Car ist die Oberklasse aller Autos und definiert deren öffentliches Interface.
	• Objektfunktionen:
		○ bool checkCar(): Überprüft die Fahrtüchtigkeit des Autos und gibt true zurück, wenn die Fahrtüchtigkeit gegeben ist. Bei gefundenen Problemen wird eine Exception geworfen (BrokenMotorException, ElectronicsFaultException oder EmissionsTooDirtyException).
		○ int getRequiredDrivingLicence(): Gibt die benötigte Führerscheinklasse zurück.
		○ int getPassengerCount(): Gibt die Anzahl der Passagierplätze zurück.

Konkrete Autotypen
Es gibt vier konkrete Autotypen:
	• VW Bus
		○ 8 Passagierplätze
		○ Führerscheinklasse: 2
		○ Hat eine 5% Wahrscheinlichkeit eine BrokenMotorException zu werfen.
		○ Hat eine 10% Wahrscheinlichkeit eine ElectronicsFaultException zu werfen.
		○ Eine EmissionsTooDirtyException kann bei diesem Fahrzeug nicht vorkommen.
	• Ford Focus
		○ 4 Passagierplätze
		○ Führerscheinklasse: 1
		○ Hat eine 8% Wahrscheinlichkeit eine BrokenMotorException zu werfen.
		○ Hat eine 6% Wahrscheinlichkeit eine ElectronicsFaultException zu werfen.
		○ Hat eine 15% Wahrscheinlichkeit eine EmissionsTooDirtyException zu werfen.
	• Ferrari F40
		○ 1 Passagierplatz
		○ Führerscheinklasse: 3
		○ Ein Ferrari kann nicht kaputt gehen, daher kommt es bei diesem Fahrzeug zu keiner Exception.
	• Kleinbus
		○ 20 Passagierplätze
		○ Führerscheinklasse: 4
		○ Hat eine 15% Wahrscheinlichkeit eine BrokenMotorException zu werfen.
		○ Hat eine 10% Wahrscheinlichkeit eine ElectronicsFaultException zu werfen.
		○ Hat eine 5% Wahrscheinlichkeit eine EmissionsTooDirtyException zu werfen.
		
Exceptions
Die Basisklasse aller Exceptions soll CarRentalException heißen, die wiederum von std::exception erbt. Überschreiben Sie die Funktion const char* what() der Klasse std::exception, sodass eine aussagekräftige Fehlermeldung zurückgegeben wird (alternativ können Sie auch von std::runtime_error erben und die Fehlermeldung dessen Konstruktor übergeben).
Wenn Sie es für notwendig erachten, können Sie auch weitere benutzerdefinierte Exception-Klassen neben den schon oben genannten hinzufügen.

Interne Implementierung
Wie Sie die gewünschte Funktionalität intern implementieren, bleibt Ihnen überlassen. Wählen Sie passende Sichtbarkeiten und vergessen Sie nicht, wenn möglich das const Keyword bei Eingabeparametern und wenn passend Call-by-Reference zu verwenden.

Wählen Sie selbstständig passende Datencontainer aus. Es darf zu keinem Zeitpunkt zu einem Speicher- oder sonstigen Ressourcenleck kommen.

Überlegen Sie sich außerdem, wo sie dynamische Bindung verwenden.

Separieren Sie bitte die main() Funktion in einer eigenen Datei, die Sie main.cpp nennen. Der Hintergrund ist, dass die automatischen Tests ihre eigene main() Funktion verwenden, daher muss diese einfach austauschbar sein. Der Inhalt ihrer main()-Funktion ist für die Prüfung nicht relevant. Sorgen Sie bitte auch dafür, dass alle relevanten Klassen (CarRental und alle Unterklassen von Car) einen funktionierenden Default-Konstruktor besitzen.

Die restlichen Dateien können Sie benennen, wie Sie wollen. Benennen Sie aber die Klassen und Funktionen genauso wie angegeben!
Geben Sie mit der Abgabe auch ein Makefile ab, welches Ihr Programm kompiliert.

Unverbindliche Schritt-für-Schritt Anleitung
	1. Beginnen Sie mit der Implementierung der Klasse Car und deren Subklassen. Testen Sie diese ausführlich.
	2. Implementieren Sie anschließend die Klasse CarRental und testen diese ausführlich.
In [ ]:
![image](https://github.com/claner2804/Exam-CarRental/assets/131294860/5f50664e-7df6-46a7-94e1-3064c1b57ae6)
