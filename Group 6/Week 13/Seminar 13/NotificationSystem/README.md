# Задача: Eventy

Изградете система за известяване за платформата **Eventy** — платформа за организиране на събития (концерти, конференции, работилници). Потребителите се абонират за платформата и получават известия за събитията, които ги интересуват, по предпочитан от тях канал (SMS, Email, Discord).

## Recipient

Адресат с:
- адрес (низ)
- име

Без default constructor. Поддържа извеждане на стандартния изход.

## Notifier (полиморфна йерархия)

Базов клас за канал за изпращане. Съдържа име на изпращач и виртуален метод `send(recipient, message)`.

Конкретни канали:

| Канал | Адрес | Формат на изхода |
|---|---|---|
| **SMS** | започва с `+` или само цифри | `[SMS from <sender>] To <addr> (<name>): <msg>`  |
| **Email** | съдържа `@` и `.` | `[EMAIL from <sender>]\nTo: <addr> (<name>)\nSubject: Notification\nBody: <msg>` |
| **Discord** | започва с `@` или `#` | `[DISCORD from <sender>] <addr>: **<msg>**` |

## Създаване на канал

Системата трябва да създава **автоматично** правилния канал спрямо формата на адреса. Викащият код не трябва да знае конкретните типове. При невалиден адрес — грешка.

## ISubscriber (полиморфна йерархия)

Базов клас за абонат на платформата с метод `onEvent(eventType, message)`.

Конкретни абонати:

**UserSubscriber** — регистриран потребител на Eventy:
- адресат (как да го намери платформата)
- списък от типове събития, за които иска да получава известия
- при `onEvent` проверява типа; ако го интересува — Eventy му праща известие на адресата чрез подходящия канал

**FileLogSubscriber** — audit log на платформата:
- път до файл
- при `onEvent` записва събитието във файла във формат: `[<eventType>] <message>`
- реагира на **всички** събития (не филтрира) — служи като лог за администраторите
- файлът се отваря в режим append (добавя в края, не презаписва)

## Eventy

Самата платформа — публикува събития към своите абонати:
- `subscribe(subscriber)` — потребител се регистрира на платформата
- `unsubscribe(subscriber)` — потребител се отписва
- `publish(eventType, message)` — платформата обявява събитие на всички абонати

Eventy държи **един общ списък** от абонати и не знае конкретните типове.

## Пример

```cpp
Eventy eventy;

// Иван иска да знае за нови събития и за разпродажби на билети
auto ivan  = std::make_shared<UserSubscriber>(
    Recipient("Иван","+359888123456"),
    std::vector<std::string>{"event_announced", "ticket_sale"}, "Eventy");

// Мария се интересува само от отменени събития
auto maria = std::make_shared<UserSubscriber>(
    Recipient("Мария","maria@example.com"),
    std::vector<std::string>{"event_cancelled"}, "Eventy");

// Петър следи само разпродажби
auto petar = std::make_shared<UserSubscriber>(
    Recipient("Петър","@petar"),
    std::vector<std::string>{"ticket_sale"}, "Eventy");

// Audit log — записва всичко за администраторите
auto auditLog = std::make_shared<FileLogSubscriber>("eventy.log");

eventy.subscribe(ivan);
eventy.subscribe(maria);
eventy.subscribe(petar);
eventy.subscribe(auditLog);

eventy.publish("event_announced", "Концерт на Madonna в София!");
eventy.publish("ticket_sale", "Билетите за Madonna са в продажба!");

eventy.unsubscribe(maria);
eventy.publish("event_cancelled", "Концертът на Coldplay е отменен.");
```

**Очакван изход на конзолата:**

```
[SMS from Eventy] To +359888123456 (Иван): Концерт на Madonna в София!

[SMS from Eventy] To +359888123456 (Иван): Билетите за Madonna са в продажба!
[DISCORD from Eventy] @petar: **Билетите за Madonna са в продажба!**

```

> Забележка: третото събитие (`event_cancelled`) не извежда нищо на конзолата — Мария е отписана, Иван и Петър не са абонирани за този тип. Но **остава в лог файла**.

**Съдържание на `eventy.log` след изпълнението:**

```
[event_announced] Концерт на Madonna в София!
[ticket_sale] Билетите за Madonna са в продажба!
[event_cancelled] Концертът на Coldplay е отменен.
```
