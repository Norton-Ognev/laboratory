#!/bin/bash

# ./bash_lab1.sh /path/to/logs 1
# ./bash_lab1.sh /path/to/logs 2 2025-10-27
#Верните нас на C, мне не особо зашло на Bash, хотя всё равно занимательная вещь

archive_files() {
    local dir="$1"
    local current_date=$(date +%Y-%m-%d)

    echo "Start arh on dir: $dir"

    if [ ! -d "$dir" ]; then
        echo "Error: Dir '$dir' not found"
        return 1
    fi

    cd "$dir" || return 1

    for file in *; do
        if [ -f "$file" ] && [[ ! "$file" =~ \.tar$ ]]; then
            local archive_name="${file}_${current_date}.tar"
            tar -cf "$archive_name" "$file"
            
            if [ $? -eq 0 ]; then
                echo "Compl: $archive_name"
                rm "$file"
            else
                echo "Error arch $file"
            fi
        fi
    done
    echo "arch comlp!"
}

delete_old_files() {
    local dir="$1"
    local cutoff_date="$2"

    if [ ! -d "$dir" ]; then
        echo "Error: Dir '$dir' not found"
        return 1
    fi

    if ! [[ "$cutoff_date" =~ ^[0-9]{4}-[0-9]{2}-[0-9]{2}$ ]]; then
        echo "Error: Date. YYYY-MM-DD"
        return 1
    fi
    
    local cutoff_timestamp=$(date -d "$cutoff_date" +%s 2>/dev/null)
    if [ $? -ne 0 ]; then
        echo "Error: Date. YYYY-MM-DD"
        return 1
    fi
    
    cd "$dir" || return 1
    local deleted_count=0

    for file in *; do
        if [ -f "$file" ]; then
            local file_date="${file##*_}"
            file_date="${file_date%.tar}"
            if [[ "$file_date" =~ ^[0-9]{4}-[0-9]{2}-[0-9]{2}$ ]]; then
                local file_timestamp=$(date -d "$file_date" +%s 2>/dev/null)
                if [ $? -eq 0 ] && [ "$file_timestamp" -lt "$cutoff_timestamp" ]; then
                    rm "$file"
                    ((deleted_count++))
                fi
            fi
        fi
    done

    echo "Deleted: $deleted_count"
}
directory="$1"
mode="$2"
date_param="$3"

case "$mode" in
    1)
        if [ $# -ne 2 ]; then
            echo "Error"
            exit 1
        fi
        archive_files "$directory"
        ;;
    2)
        if [ $# -ne 3 ]; then
            echo "Error: Date"
            exit 1
        fi
        delete_old_files "$directory" "$date_param"
        ;;
    *)
        echo "Error: $mode"
        exit 1
        ;;
esac
