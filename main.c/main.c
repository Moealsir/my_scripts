#!/bin/bash

while true; do
    read -p "Enter a file name (or 'q' to quit): " file_name

    if [ "$file_name" = "q" ]; then
        echo "Exiting..."
        break
    fi

    # Ensure the user enters a valid number as the file name
    if [[ ! $file_name =~ ^[0-9]+$ ]]; then
        echo "Invalid input. Please enter a valid number."
        continue
    fi

    # Prompt the user to enter the content
    echo "Enter the content for $file_name-main.c (Ctrl-D to finish):"
    file_content=""
    while IFS= read -r line; do
        file_content+="$line"$'\n'
    done

    # Create the file
    file="$file_name-main.c"
    echo "$file_content" > "$file"
    echo "File $file has been created."

done

