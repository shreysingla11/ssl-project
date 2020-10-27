#!/bin/bash
python3 Backend/manage.py makemigrations
python3 Backend/manage.py migrate
cd Frontend && ng serve & pids=$!
cd Backend && python3 manage.py runserver & pids+=" $!"

trap "kill $pids" SIGTERM SIGINT
wait $pids