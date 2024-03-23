void BuildTeam(Pokemon* inventory) {
    if (!inventory) {
        cout << "Inventory is empty. Cannot build a team.\n";
        return;
    }

    cout << "Select 5 Pokemon for your team:\n";
    DisplayInventory(inventory);

    Pokemon* team[5] = { nullptr };

    for (int i = 0; i < 5; ++i) {
        int choice;
        cout << "Select Pokemon " << i + 1 << ": ";
        cin >> choice;

        int count = 1;
        Pokemon* current = inventory;
        while (current && count < choice) {
            current = current->next;
            count++;
        }

        if (!current) {
            cout << "Invalid selection. Try again.\n";
            --i;  
            continue;
        }

        team[i] = current;
    }

    cout << "Your team has been selected:\n";
    for (int i = 0; i < 5; ++i) {
        if (team[i]) {
            cout << i + 1 << ". Name: " << team[i]->name << ", Type: " << team[i]->type << ", Level: " << team[i]->level << "\n";
        }
    }
}
