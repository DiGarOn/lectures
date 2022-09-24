/*

Основы MVC в библиотеке QT

MVC - модель представления контролер 
Model View Controller

Model - nовечает за данные и за взаимосвязь между ними 
View - овечает за отображение данных моделей
Controller - позволяет менять параметры модели / инициировать данные с учетов правил, составленных в самой модели 

Способ разделения абстракций данных, которые где-то хранятся 
Контроллер выполняет настройку параметров и изменения параметров 

QListWidget 
addItem(Item)
addItem's(List)

МОДЕЛЬ/ПРЕДСТАВЛЕНИЕ 
QGraphicsScene
 |
\/
QObject
^
|
QWidget
^
|
QGraphicsView ::::::: QGraphicsScene


QGraphicsItem 
^    ^    ^    ^    ^
|    |    |    |    |
|    |    |    |    QAstractGraphicsShapeItem
|    |    |    QGraphicsItemGroup
|    |    QGraphicsLineItem
|    QGraphicsObject -> QObject
QGraphicsWidget -> QWidget



*/
