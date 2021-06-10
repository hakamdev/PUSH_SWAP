#!/bin/bash
ARG="$1"; ./../push_swap $ARG | ./../checker $ARG; ./push_swap $ARG | wc -l