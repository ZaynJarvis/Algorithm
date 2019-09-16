import { Component, OnInit } from '@angular/core';
import { AngularFirestore } from '@angular/fire/firestore';
import { Problem } from '../../../src/model/Problem';
import { generateUUID } from '../util';
@Component({
  selector: 'app-add-problem',
  templateUrl: './add-problem.component.html',
  styleUrls: ['./add-problem.component.scss'],
})
export class AddProblemComponent implements OnInit {
  model: Problem;
  difficulties = ['Easy', 'Medium', 'Normal', 'Hard'];
  submitted = false;

  constructor(private db: AngularFirestore) {}

  ngOnInit() {
    this.modelInit();
  }

  modelInit() {
    this.model = new Problem(generateUUID(), '', '', '', Date.now(), 2);
  }
  onSubmit() {
    this.db
      .collection('problem')
      .doc(this.model.id)
      .set(this.model.parse(), { merge: true });
  }

  onClear() {
    this.modelInit();
  }
}
