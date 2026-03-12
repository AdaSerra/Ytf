## Ytfeed‑cli

![License](https://img.shields.io/badge/license-MIT-blue.svg) ![Platform](https://img.shields.io/badge/platform-Windows-0078D6.svg) ![Language](https://img.shields.io/badge/language-C%2B%2B20-00599C.svg) ![SQLite](https://img.shields.io/badge/database-SQLite-003B57.svg) ![WinHTTP](https://img.shields.io/badge/network-WinHTTP-0082C9.svg) ![MSXML6](https://img.shields.io/badge/XML-MSXML6-6A5ACD.svg)

A fast, lightweight YouTube RSS fetcher and SQLite indexer for Windows.

### 📌 Overview
Ytfeed‑cli is a minimalistic command‑line tool designed to fetch YouTube channel feeds via RSS, parse them using MSXML6, and store normalized video metadata into a local SQLite database.
It is the console counterpart of a more complete WinRT/WinUI application, sharing the same core logic but optimized for automation, scripting,  and low‑overhead usage.

The tool is built entirely on native Windows APIs:

WinHTTP for HTTPS requests

MSXML6 for XML parsing

SQLite (winsqlite3) for persistent storage

C++20 for performance and portability

Its goal is simple: track multiple YouTube channels, store their latest videos, and present them sorted by publication date.

### ✨ Features
Fetches YouTube RSS feeds directly (no API key required)

Parses XML using MSXML6 with robust error handling

Stores channels and videos in SQLite with conflict‑free inserts

Automatically trims old videos (keeps the latest 30 per channel)

Supports batch insertion for high performance

Validates YouTube channel IDs with strict regex

Validates Windows filenames safely

UTF‑8 → UTF‑16 conversion for full Unicode support

Clean, deterministic output suitable for scripting

### 🛠 Requirements

- Windows 10 or later
- Visual Studio (MSVC)
- SQLite (winsqlite3.lib)
- MSXML6
- WinHTTP

All dependencies are native to Windows.

### 🚀 Usage
Basic syntax
```
ytfeed-cli [options]
 
Option	Description
  -A, --add <id>         Add a single YouTube channel ID
  -C, --channel          Show all channels (ID + name) stored in the database
  -D, --delete <name>    Delete a channel by name
  -F, --feed <name>      Show feeds from a single channel by name
  -L, --load <file>      Load a list of YouTube channel IDs from a text file
  -N, --new              Show feeds published in last 24 hours
  -S, --show <number>    Limit the number of feeds printed (default: 20)
  -X, --stat             Show feeds and database statistics
  -W, --web              Generate a static html page with last feeds
  -H, --help             Show this help message
  
```

📄 Input file format (-L)

A plain text file containing one YouTube channel ID per line:
```
UC_x5XG1OV2P6uZZ5FSM9Ttw
UC4R8DWoMoI7CAwX8_LjQHig
UCYO_jab_esuFRV4b17AJtAw
```
Invalid IDs are rejected with a warning.

### 🔍 Example commands
No one arguments, default output:
```
ytfeed-cli

New Video(s): 225
New Channel(s): 15
09:00:00 12-03-2026    NPR Music                  Madi Diaz: Tiny Desk Concert                                   https://www.youtube.com/watch?v=-VwcJdXJoxs
23:01:48 11-03-2026    Android Developers         Expanding our stage for PC and paid titles                     https://www.youtube.com/watch?v=tuXjvBXjkw8
18:16:37 11-03-2026    Linus Tech Tips            Apple’s Co-Founder Left to Make THIS??                         https://www.youtube.com/watch?v=VxoB4vM1pUM
14:30:26 11-03-2026    Computerphile              Vector Search with LLMs - Computerphile                        https://www.youtube.com/watch?v=YDdKiQNw80c
14:19:12 11-03-2026    NPR Music                  #DeskOfTheDay: "Goodbye, Cowboy," Belltower                    https://www.youtube.com/watch?v=ywtpXmRwUC8   S
23:40:30 10-03-2026    Marques Brownlee           Macbook Neo Review: Better than you Think!                     https://www.youtube.com/watch?v=iGeXGdYE7UE
17:58:22 10-03-2026    Linus Tech Tips            We Built the ULTIMATE Gaming Firetruck                         https://www.youtube.com/watch?v=zn5lAEdv2DY
15:01:48 10-03-2026    TED-Ed                     What happens when you break a bone? - Gurpreet Baht and Nata   https://www.youtube.com/watch?v=gVXoAbeB8QI
15:00:01 10-03-2026    Kurzgesagt – In a Nutshel  This Is the Scariest Place in The Universe                     https://www.youtube.com/watch?v=yDAAlojz8NU
14:09:59 10-03-2026    NPR Music                  #DeskOfTheDay: "Return to Sender," KC Shane & The Belonging    https://www.youtube.com/watch?v=Mt64jh5hGxM   S
23:03:52 09-03-2026    Vsauce                     An Illusion You Can Hug                                        https://www.youtube.com/watch?v=_Nr4mvdkEVw   S
```
Load channels from file:
```
ytfeed-cli -L channels.txt
```
Add a single channel:
```
ytfeed-cli -A UC_x5XG1OV2P6uZZ5FSM9Ttw
```
Show the latest 10 videos:
```
ytfeed-cli -S 10
```
Show some statistics:
```
ytfeed-cli -X

---------- YOUTUBE STATISTICS -----------

Total Channels: 15
Total Videos: 225
Total Videos Shorts: 72
Recent Videos (last 24 hours): 5
Average gap between videos: 115.702 hours

----------- ACTIVITY LAST 7 DAYS (39 Videos) -------------------------             ---------------- TOP CHANNELS -------------------

2026-03-12 | # (1)                                                                 NPR Music                 | ########### (11)
2026-03-11 | #### (4)                                                              Linus Tech Tips           | ####### (7)
2026-03-10 | ##### (5)                                                             Kurzgesagt – In a Nutshell | #### (4)
2026-03-09 | ############## (14)                                                   Android Developers        | #### (4)
2026-03-08 | ## (2)                                                                thenewboston              | ### (3)
2026-03-07 | ### (3)                                                               Marques Brownlee          | ### (3)
2026-03-06 | ##### (5)                                                             TED-Ed                    | ## (2)
2026-03-05 | ####### (7)                                                           Computerphile             | ## (2)
2026-03-04 | #### (4)                                                              Vsauce                    | # (1)
2026-03-03 | ##### (5)                                                             Veritasium                | # (1)

----------- ACTIVITY LAST 2 MONTHS Weekly (129 Videos) ----------------            ---------------- TOP CHANNELS -------------------

2026-03-09 - 2026-03-15 | ##### (10)                                               TED-Ed                    | ############### (15)
2026-03-02 - 2026-03-08 | #################### (40)                                NPR Music                 | ############### (15)
2026-02-23 - 2026-03-01 | ######### (19)                                           Marques Brownlee          | ############### (15)
2026-02-16 - 2026-02-22 | ######## (16)                                            Linus Tech Tips           | ############### (15)
2026-02-09 - 2026-02-15 | ##### (11)                                               Kurzgesagt – In a Nutshell | ############### (15)
2026-02-02 - 2026-02-08 | #### (9)                                                 Android Developers        | ############### (15)
2026-01-26 - 2026-02-01 | #### (9)                                                 Veritasium                | ############ (12)
2026-01-19 - 2026-01-25 | #### (8)                                                 Fireship                  | ########## (10)
2026-01-12 - 2026-01-18 | ### (7)                                                  Computerphile             | ######## (8)

-------------------------------------------------------------- NEWEST AND OLDEST VIDEOS --------------------------------------------------------------

09:00:00 12-03-2026    NPR Music                  Madi Diaz: Tiny Desk Concert                                   https://www.youtube.com/watch?v=-VwcJdXJoxs
12:45:11 28-03-2023    CGP Grey                   How a Video Game Gave Antarctica Its Flag                      https://www.youtube.com/watch?v=U0wTDK0VOeY

----------- DATABASE STATISTICS ----------------

Database size: 68 kb
Schema version 2
Integrity: ok
Freelist pages: 0
Journal mode: wal
Synchronous mode: 1
Foreign Keys: 1
Total table :2
```

Show 
🧠 How it works (internal pipeline)

- Parse arguments  
- Validate filenames, numeric limits, and channel IDs.
- Load channels from file (-L) or single ID (-a).
- Fetch RSS feeds  
- Using WinHTTP with a lightweight user agent.
- Parse XML  
- Extract: channel name, video title, video ID, publication timestamp
- Insert into SQLite  
  Using prepared statements and batch transactions.
- Trim old videos  
  Keep only the latest 30 per channel.
- Sort and display  
  Videos are sorted by timestamp (newest first).

🧩 Database schema
```
  Channels Table
| Column | Type    |  Description       |
|--------|---------|--------------------|
| Id     | TEXT PK | YouTube Channel Id |
| Name   | TEXT    | Channel name       | (fetched from feed)

 Videos Table
| Column    | Type    |  Description             |
|-----------|---------|------------------------- |
| Id        | TEXT PK | YouTube Video Id         |  
| Title     | TEXT    | Video title              | 
| Author    | TEXT    | Channel name             | FK REFERENCES Channels(Name)
| Short     | INTEGER | Short Video (1) or not(0)|
| Timestamp | INTEGER | Unix timestamp           |


```
### ⚙ Build instructions
```
MSVC (Developer Command Prompt)
cl ytfeed-cli.cpp /O2 /EHsc /std:c++20
```
