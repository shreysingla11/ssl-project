#!/bin/bash

#!/bin/bash
cd Frontend && ng serve & pids=$!
cd Backend && python3 manage.py runserver & pids+=" $!"

trap "kill $pids" SIGTERM SIGINT
wait $pids