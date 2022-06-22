@page 4 Use Case Diagram
@tableofcontents

@startuml Use Case Diagram

left to right direction

actor User
actor Roomba

rectangle RoombaFunctions {
User --> (Start Cleaning)
User --> (Start RemoteControl)
User --> (Control Lights)
User --> (Control Brush)
User --> (Control Vacuum)
User <-- (Show Battery Status)
User <-- (Vacuumchamber full)
}

(Vacuumchamber full) <-down- Roomba
(Show Battery Status) <-down- Roomba
(Start Cleaning) -> Roomba
(Start RemoteControl) -> Roomba
(Control Lights) -> Roomba
(Control Brush) -> Roomba
(Control Vacuum) -> Roomba


@enduml