import { Component, OnInit } from '@angular/core';
import { AngularFirestore } from '@angular/fire/firestore';
import { Problem } from '../../../src/model/Problem';

@Component({
  selector: 'app-add-problem',
  templateUrl: './add-problem.component.html',
  styleUrls: ['./add-problem.component.scss'],
})
export class AddProblemComponent implements OnInit {
  constructor(private db: AngularFirestore) {}
  difficulties = ['Easy', 'Medium', 'Normal', 'Hard'];

  model = new Problem('', '', '', Date.now(), 2);

  submitted = false;

  ngOnInit() {}

  onSubmit() {
    this.db.collection('problem').add(this.model.parse());
  }

  onClear() {
    this.model = new Problem('', '', '', Date.now(), 2);
  }
}
